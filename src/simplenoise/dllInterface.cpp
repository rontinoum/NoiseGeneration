#include "simplenoise/NoiseGeneratorSimple.h"

extern "C"
{
    char* dllName = "Simple";
    size_t dllNameLength = 6;

    base::NoiseGeneratorInterface* interface_ptr = nullptr;

    SIMPLENOISE_API base::NoiseGeneratorInterface* getInterface()
    {
        if(interface_ptr == nullptr)
            interface_ptr = (base::NoiseGeneratorInterface*)new simplenoise::NoiseGeneratorSimple();

        return interface_ptr;
    }

    SIMPLENOISE_API void destroyInterface()
    {
        if(interface_ptr != nullptr)
            delete interface_ptr;
    }

    SIMPLENOISE_API const size_t& getNameLength()
    {
        return dllNameLength;
    }

    SIMPLENOISE_API char* const getName()
    {
        return dllName;
    }
}
