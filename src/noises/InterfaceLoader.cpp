#include "noises/InterfaceLoader.h"

#include <QtCore/QDir>

#include "qdebug.h"

NOISES_NAMESPACE_BEGIN

InterfaceLoader::InterfaceLoader()
{

}

InterfaceLoader::~InterfaceLoader()
{

}

void InterfaceLoader::loadDll(const QString& dll)
{
    qDebug() << "Load Dll: " << dll;

    // load dll
    HINSTANCE dll_instance = LoadLibrary(dll.toUtf8().data());

    if(dll_instance == nullptr)
        return;

    // get function ptr
    DllInterface dll_interface;

    dll_interface._instance = dll_instance;
    dll_interface._get_interface = (GetInterfacePtrFunctor)GetProcAddress(dll_instance, "getInterface");
    dll_interface._destroy_interface = (DestroyInterfacePtrFunctor)GetProcAddress(dll_instance, "destroyInterface");
    dll_interface._get_name_length = (GetNameLengthFunctor)GetProcAddress(dll_instance, "getNameLength");
    dll_interface._get_name = (GetNameFunctor)GetProcAddress(dll_instance, "getName");
    
    bool all_setup = true;

    all_setup &= dll_interface._get_interface != nullptr;
    all_setup &= dll_interface._destroy_interface != nullptr;
    all_setup &= dll_interface._get_name_length != nullptr;
    all_setup &= dll_interface._get_name != nullptr;
    
    if(!all_setup)
    {
        bool freed = FreeLibrary(dll_instance);

        qDebug() << " -> Can't resolve external functions";

        return;
    }

    // get name
    size_t dll_name_length = 0;
    char* dll_name = nullptr;

    dll_name_length = dll_interface._get_name_length();
    dll_name = dll_interface._get_name();

    if(dll_name_length == 0 || dll_name == nullptr)
    {
        bool freed = FreeLibrary(dll_instance);

        qDebug() << " -> Missing Name";

        return;
    }

    QString name(dll_name_length);
    for(size_t i = 0; i < dll_name_length; i++)
        name[i] = dll_name[i];

    if(_dlls.contains(name))
    {
        bool freed = FreeLibrary(dll_instance);

        qDebug() << " -> Dll with same name detected";

        return;
    }

    _dlls.insert(name, dll_interface);

    qDebug() << " -> Loaded";
}

void InterfaceLoader::getInterfaces()
{
    QMap<QString, DllInterface> dlls;

    QMap<QString, DllInterface>::iterator iter = _dlls.begin();
    while(!_dlls.empty())
    {
        // get Interface
        base::NoiseGeneratorInterface* const interface_ptr = iter.value()._get_interface();

        if(interface_ptr == nullptr)
        {
            bool freed = FreeLibrary(iter.value()._instance);

            qDebug() << " -> Can't allocate Interface";

            _dlls.erase(iter);

            iter = _dlls.begin();

            continue;
        }

        _dll_interfaces.insert(iter.key(), interface_ptr);

        dlls.insert(iter.key(), iter.value());

        _dlls.erase(iter);

        iter = _dlls.begin();
    }

    // setup new dlls
    _dlls = dlls;
}

void InterfaceLoader::detectInterfaceDlls()
{
    QDir application_dir = QDir::current();
    QStringList dlls = application_dir.entryList(QStringList() << "*.dll", QDir::Files | QDir::NoSymLinks);

    for(const auto& dll : dlls)
        loadDll(dll);

    getInterfaces();
}

void InterfaceLoader::load()
{
    // get all dlls
    detectInterfaceDlls();
}

base::NoiseGeneratorInterface* const InterfaceLoader::get(const QString& name) const
{ 
    if(!_dll_interfaces.contains(name))
        return nullptr;

    return _dll_interfaces[name];
}

void InterfaceLoader::unload()
{
    for(const auto& dll : _dlls)
        dll._destroy_interface();

    _dlls.clear();
    _dll_interfaces.clear();
}

base::NoiseGeneratorInterface* const InterfaceLoader::loadInterface(const QString& dll)
{
    return nullptr;
}

NOISES_NAMESPACE_END
