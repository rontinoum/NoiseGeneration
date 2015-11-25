#include "noises/NoiseController.h"

#include "noises/NoiseWindow.h"

NOISES_NAMESPACE_BEGIN

NoiseController::NoiseController(NoiseWindow* const noise_window) : _active_noise_generator(nullptr), _noise_window(noise_window)
{
    
}

NoiseController::~NoiseController()
{
    clearInterfaces();
}

void NoiseController::init()
{
    // connect window and controller
    connect(_noise_window, &NoiseWindow::refreshNoise, this, &NoiseController::onRefreshNoise);
    connect(_noise_window, &NoiseWindow::reload, this, &NoiseController::onReload);

    onReload();
}

void NoiseController::initInterfaces()
{
    _interface_loader.load();
    _interface_names = _interface_loader.getInterfaceNames();
}

void NoiseController::clearInterfaces()
{
    _interface_names.clear();
    _interface_loader.unload();
    _active_noise_generator = nullptr;
}

void NoiseController::onReload()
{
    clearInterfaces();
    initInterfaces();

    // set values in window
    _noise_window->setNoiseMethods(_interface_names);
}

void NoiseController::onRefreshNoise(const QString& noise_name)
{
    if(!_interface_names.contains(noise_name))
    {
        _active_noise_generator = nullptr;

        return;
    }

    _active_noise_generator = _interface_loader.get(noise_name);
}

NOISES_NAMESPACE_END
