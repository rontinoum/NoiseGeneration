#pragma once

#include "simplenoise/module_config.h"

#include "base/NoiseGeneratorInterface.h"

SIMPLENOISE_NAMESPACE_BEGIN

class NoiseGeneratorSimple : base::NoiseGeneratorInterface
{
public:
    NoiseGeneratorSimple();
    ~NoiseGeneratorSimple();

    virtual float getNoise(const float& value) final override;
};

SIMPLENOISE_NAMESPACE_END
