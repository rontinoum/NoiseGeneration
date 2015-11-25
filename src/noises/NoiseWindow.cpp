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

    // connect widgets
    connect(_main_widget._bt_reload_methods, &QPushButton::pressed, this, &NoiseWindow::reload);
    connect(_main_widget._cb_methods, SIGNAL(activated(const QString&)), this, SIGNAL(refreshNoise(const QString&)));
}

void NoiseWindow::setNoiseMethods(const QStringList& noises)
{
    _main_widget._cb_methods->clear();
    
    for(const auto& name : noises)
        _main_widget._cb_methods->addItem(name);

    // refresh noise
    if(_main_widget._cb_methods->count() != 0)
        emit refreshNoise(_main_widget._cb_methods->itemText(0));
}

NOISES_NAMESPACE_END
