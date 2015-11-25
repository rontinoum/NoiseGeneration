#pragma once

#include "base/module_config.h"

BASE_NAMESPACE_BEGIN

class BASE_API NoiseGeneratorInterface
{
public:
    NoiseGeneratorInterface();
    ~NoiseGeneratorInterface();

    virtual float getNoise(const float& value) = 0;
};

BASE_NAMESPACE_END
