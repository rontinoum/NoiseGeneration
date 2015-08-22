#include "noises/NoiseController.h"

NOISES_NAMESPACE_BEGIN

NoiseController::NoiseController() : _active_noise_generator(nullptr)
{

}

NoiseController::~NoiseController()
{
    clear();
}

void NoiseController::init()
{
    _interface_loader.load();
    _interface_names = _interface_loader.getInterfaceNames();
}

void NoiseController::clear()
{
    _interface_names.clear();
    _interface_loader.unload();
    _active_noise_generator = nullptr;
}

void NoiseController::reload()
{
    clear();

    init();
}

void NoiseController::setActive(const QString& name)
{
    if(!_interface_names.contains(name))
    {
        _active_noise_generator = nullptr;

        return;
    }

    _active_noise_generator = _interface_loader.get(name);
}

NOISES_NAMESPACE_END
