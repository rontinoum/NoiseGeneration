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
    _controller = new NoiseController();
    _window = new NoiseWindow();

    _window->show();
}

NOISES_NAMESPACE_END
