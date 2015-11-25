#pragma once

#include "noises/module_config.h"

#include <QtWidgets/QWidget>

NOISES_NAMESPACE_BEGIN

class Noise1DWidget : public QWidget
{
public:
    Noise1DWidget(QWidget* parent = 0, Qt::WindowFlags flags = 0);
    ~Noise1DWidget();
};

NOISES_NAMESPACE_END
