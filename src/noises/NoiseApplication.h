#pragma once

#include "noises/module_config.h"

#include <QtWidgets/QApplication>

NOISES_NAMESPACE_BEGIN

class NoiseController;
class NoiseWindow;

class NoiseApplication : public QApplication
{
    Q_OBJECT;

public:
    NoiseApplication(int& argc, char** argv);
    ~NoiseApplication();

public slots:
    void run();

private:
    void init();

private:
    NoiseController* _controller;
    NoiseWindow* _window;
};

NOISES_NAMESPACE_END
