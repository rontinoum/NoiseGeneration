#include "noises/NoiseApplication.h"

#include <QtCore/QTimer>

int main(int argc, char** argv)
{
    noises::NoiseApplication* app = new noises::NoiseApplication(argc, argv);
    QTimer::singleShot(0, app, SLOT(run(void)));

    int result = app->exec();

    delete app;

    return result;
}
