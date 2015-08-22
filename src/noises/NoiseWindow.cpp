#include "noises/NoiseWindow.h"

NOISES_NAMESPACE_BEGIN

NoiseWindow::NoiseWindow(QWidget* parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
    QWidget* central_widget = new QWidget(this);
    _main_widget.setupUi(central_widget);
    _main_widget.retranslateUi(central_widget);

    setCentralWidget(central_widget);
}

NoiseWindow::~NoiseWindow()
{

}

NOISES_NAMESPACE_END
