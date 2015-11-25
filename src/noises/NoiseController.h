#pragma once

#include "noises/module_config.h"
#include "noises/InterfaceLoader.h"

#include "base/module_config.h"

BASE_NAMESPACE_BEGIN
class NoiseGeneratorInterface;
BASE_NAMESPACE_END

#include <QtCore/QObject>
#include <QtCore/QStringList>

NOISES_NAMESPACE_BEGIN

class NoiseWindow;

class NoiseController : public QObject
{
    Q_OBJECT;

public:
    NoiseController(NoiseWindow* const noise_window);
    ~NoiseController();

    void init();

public slots:
    void onReload();
    void onRefreshNoise(const QString& noise_name);

private:
    void initInterfaces();
    void clearInterfaces();

private:
    InterfaceLoader _interface_loader;
    base::NoiseGeneratorInterface* _active_noise_generator;
    QStringList _interface_names;

    NoiseWindow* const _noise_window;
};

NOISES_NAMESPACE_END
