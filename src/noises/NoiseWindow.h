#pragma once

#include "noises/module_config.h"
#include "noises/main_wnd_uic.h"

#include <QtWidgets/QMainWindow>

NOISES_NAMESPACE_BEGIN

class NoiseWindow : public QMainWindow
{
    Q_OBJECT

public:
    NoiseWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);
    ~NoiseWindow();

    void init();

    void setNoiseMethods(const QStringList& noises);

signals:
    void refreshNoise(const QString& noise_name);
    void reload();

private:
    Ui::MainWidget _main_widget;
};

NOISES_NAMESPACE_END
