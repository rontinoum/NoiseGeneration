#pragma once

#include "base/module_config.h"
#include "noises/module_config.h"

#include "base/NoiseGeneratorInterface.h"

#include "QtCore/QString"
#include "QtCore/QMap"

#include <windows.h>

BASE_NAMESPACE_BEGIN
class Interface;
BASE_NAMESPACE_END

NOISES_NAMESPACE_BEGIN

typedef base::NoiseGeneratorInterface* CREATEINTERFACEHANDLE;
typedef void DESTROYINTERFACEHANDLE;
typedef const size_t& NAMELENGTHHANDLE;
typedef char* const NAMEHANDLE;

typedef CREATEINTERFACEHANDLE(*GetInterfacePtrFunctor)(void);
typedef DESTROYINTERFACEHANDLE(*DestroyInterfacePtrFunctor)(void);
typedef NAMELENGTHHANDLE(*GetNameLengthFunctor)(void);
typedef NAMEHANDLE(*GetNameFunctor)(void);

class InterfaceLoader
{
private:
    struct DllInterface
    {
        HINSTANCE _instance;
        GetInterfacePtrFunctor _get_interface;
        DestroyInterfacePtrFunctor _destroy_interface;
        GetNameLengthFunctor _get_name_length;
        GetNameFunctor _get_name;
        QString _version;
        QString _key;
    };

public:
    InterfaceLoader();
    ~InterfaceLoader();

    void load();
    QStringList getInterfaceNames() const;
    base::NoiseGeneratorInterface* const get(const QString& name) const;
    void unload();

private:
    void detectInterfaceDlls();
    void loadDll(const QString& dll);
    void getInterfaces();
    base::NoiseGeneratorInterface* const loadInterface(const QString& dll);

private:
    QMap<QString, DllInterface> _dlls;
    QMap<QString, base::NoiseGeneratorInterface*> _dll_interfaces;
};

NOISES_NAMESPACE_END
