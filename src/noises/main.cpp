#include "noises/InterfaceLoader.h"

int main()
{
    noises::InterfaceLoader loader;
    loader.load();

    base::NoiseGeneratorInterface* const noise_generator_simple = loader.get("Simple");

    noise_generator_simple->getNoise(1.0f);

    loader.unload();

    return 0;
}
