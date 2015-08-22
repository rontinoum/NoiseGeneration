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

class NoiseController : QObject
{
    Q_OBJECT;

public:
    NoiseController();
    ~NoiseController();

public slots:
    void setActive(const QString& name);
    void reload();

private:
    void init();
    void clear();

private:
    InterfaceLoader _interface_loader;
    base::NoiseGeneratorInterface* _active_noise_generator;
    QStringList _interface_names;
};

NOISES_NAMESPACE_END
