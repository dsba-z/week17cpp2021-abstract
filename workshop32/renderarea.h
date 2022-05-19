#ifndef RENDERAREA_H
#define RENDERAREA_H
#include "figure.h"
#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget* parent = nullptr);
    ~RenderArea();

    void addRectangle();
protected:
    Canvas* canvas;
    void paintEvent(QPaintEvent* event) override;

signals:

};

#endif // RENDERAREA_H
