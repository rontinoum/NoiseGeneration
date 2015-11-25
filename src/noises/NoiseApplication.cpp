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
    _window = new NoiseWindow();
    _controller = new NoiseController(_window);

    // init controler and window
    _window->init();
    _controller->init();

    // show window
    _window->show();
}

NOISES_NAMESPACE_END
