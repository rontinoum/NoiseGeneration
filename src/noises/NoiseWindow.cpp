#include "noises/NoiseWindow.h"

NOISES_NAMESPACE_BEGIN

NoiseWindow::NoiseWindow(QWidget* parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{

}

NoiseWindow::~NoiseWindow()
{

}

void NoiseWindow::init()
{
    QWidget* central_widget = new QWidget(this);
    _main_widget.setupUi(central_widget);

    setCentralWidget(central_widget);
}

const Ui::MainWidget& NoiseWindow::getMainWidget()
{
    return _main_widget;
}

NOISES_NAMESPACE_END
