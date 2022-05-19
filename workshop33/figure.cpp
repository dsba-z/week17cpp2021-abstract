
#include "figure.h"

#include <iostream>
#include <cmath>
#include <algorithm>


Figure::~Figure()
{

}

void Rectangle::draw(QPainter* painter) const
{
    painter->drawRect(_x1, _y1, _w, _h);
}


void Circle::draw(QPainter* painter) const
{
    painter->drawEllipse(_x1, _y1, _r*2, _r*2);
}


Circle* Canvas::addCircle(double x1, double y1, double r)
{
    Circle* cirPtr = new Circle(x1, y1, r);
    _figures.push_back(cirPtr);
    return cirPtr;
}

Rectangle* Canvas::addRectangle(double x1, double y1, double w, double h)
{
    Rectangle* recPtr = new Rectangle(x1, y1, w, h);
    _figures.push_back(recPtr);
    return recPtr;
}

void Canvas::drawAll(QPainter* painter) const
{
    for (Figure* el : _figures)
    {
        el->draw(painter);
    }
}

Canvas::~Canvas()
{
    for(Figure* fig: _figures)
        delete fig;
    _figures.clear();
}


