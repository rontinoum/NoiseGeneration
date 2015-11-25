#pragma once

#include "noises/module_config.h"

#include <QtWidgets/QWidget>

NOISES_NAMESPACE_BEGIN

class Noise2DWidget : public QWidget
{
public:
    Noise2DWidget(QWidget* parent = 0, Qt::WindowFlags flags = 0);
    ~Noise2DWidget();
};

NOISES_NAMESPACE_END
