#pragma once

#include "noises/module_config.h"

#include <QtWidgets/QWidget>

NOISES_NAMESPACE_BEGIN

class Noise3DWidget : public QWidget
{
public:
    Noise3DWidget(QWidget* parent = 0, Qt::WindowFlags flags = 0);
    ~Noise3DWidget();
};

NOISES_NAMESPACE_END
