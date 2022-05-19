#include "renderarea.h"

#include <QPainter>
#include <QRandomGenerator>

RenderArea::RenderArea(QWidget* parent)
    : QWidget(parent)
{
    canvas = new Canvas();
    
    canvas->addCircle(10, 10, 5);
    canvas->addRectangle(30, 10, 55, 55);
    update();
}

RenderArea::~RenderArea()
{
    delete canvas;
}

void RenderArea::addRectangle()
{
    int x = rand() % (width()/2);
    int y = QRandomGenerator::global()->generate() % (height()/2);
    int w = QRandomGenerator::global()->generate() % (width()/2);
    int h = QRandomGenerator::global()->generate() % (height()/2);
    canvas->addRectangle(x, y, w, h);
    update();
}

void RenderArea::paintEvent(QPaintEvent* /* event */)
{
    QPainter painter(this);
    painter.setBrush(Qt::GlobalColor::gray);
    painter.drawRect(QRect(0, 0, this->width() - 1, this->height() - 1));
    

    QBrush figBrush(Qt::GlobalColor::blue);
    QPen figPen(Qt::GlobalColor::red);
    painter.setBrush(figBrush);
    painter.setPen(figPen);
    
    painter.scale(10, 1);

    // draw the canvas
    canvas->drawAll(&painter);

}
