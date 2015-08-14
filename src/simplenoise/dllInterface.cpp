#include "simplenoise/NoiseGeneratorSimple.h"

extern "C"
{
    char* dllName = "Simple";
    size_t dllNameLength = 6;

    base::NoiseGeneratorInterface* interface_ptr = nullptr;

    D_EXPORT base::NoiseGeneratorInterface* getInterface()
    {
        if(interface_ptr == nullptr)
            interface_ptr = (base::NoiseGeneratorInterface*)new simplenoise::NoiseGeneratorSimple();

        return interface_ptr;
    }

    D_EXPORT void destroyInterface()
    {
        if(interface_ptr != nullptr)
            delete interface_ptr;
    }

    D_EXPORT const size_t& getNameLength()
    {
        return dllNameLength;
    }

    D_EXPORT char* const getName()
    {
        return dllName;
    }
}
