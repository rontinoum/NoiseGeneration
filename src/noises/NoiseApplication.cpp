#include "noises/NoiseApplication.h"

#include "noises/NoiseController.h"
#include "noises/NoiseWindow.h"

NOISES_NAMESPACE_BEGIN

NoiseApplication::NoiseApplication(int& argc, char** argv) : QApplication(argc, argv)
{
    _controller = nullptr;
}

NoiseApplication::~NoiseApplication()
{

}

void NoiseApplication::run()
{
    init();
}

void NoiseApplication::init()
{
    // instanziate controller and window
    _controller = new NoiseController();
    _window = new NoiseWindow();

    // init controler and window
    _controller->reload();
    _window->init();

    // connect window and controller
    // ...

    // set values in window
    const QStringList& names = _controller->getNames();
    const Ui::MainWidget& main_widget = _window->getMainWidget();

    main_widget._cb_methods->clear();
    for(const auto& name : names)
        main_widget._cb_methods->addItem(name);

    _window->show();
}

NOISES_NAMESPACE_END
