#pragma once

#include "noises/module_config.h"
#include "noises/main_wnd_uic.h"

#include <QtWidgets/QMainWindow>

NOISES_NAMESPACE_BEGIN

class NoiseWindow : public QMainWindow
{
public:
    NoiseWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);
    ~NoiseWindow();

    const Ui::MainWidget& getMainWidget();

    void init();

private:
    Ui::MainWidget _main_widget;
};

NOISES_NAMESPACE_END
