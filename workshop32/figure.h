#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <cmath>
#include <vector>
#include <QPainter>

class Figure
{
public:
    Figure() {}
    virtual void draw(QPainter* painter) const = 0;
    virtual ~Figure();
protected:
};


class Rectangle : public Figure
{

public:
    Rectangle (double x1 = 0, double y1 = 0, double w = 0, double h = 0)
        :_x1(x1), _y1(y1), _w(w), _h(h)
    {}

    virtual ~Rectangle(){}

public:
    virtual void draw(QPainter* painter) const override;
public:
protected:
    double _x1, _y1;
    double _w, _h;
};

class Circle : public Figure
{

public:
    Circle (double x1 = 0, double y1 = 0, double r = 0)
            :_x1(x1), _y1(y1), _r(r)
    {}

    virtual ~Circle(){}

public:
    virtual void draw(QPainter* painter) const override;

protected:
    double _x1, _y1;
    double _r;
};


class Canvas
{
public:
//    Canvas(); // added by compiler
    ~Canvas();
public:
    typedef std::vector<Figure*> Storage;

    Rectangle* addRectangle (double x1 = 0, double y1 = 0, double w = 0, double h = 0);
    Circle* addCircle (double x1 = 0, double y1 = 0, double r = 0);


    void drawAll(QPainter* painter) const;
    
    Storage getStor()
    {
        return _figures;
    }
    
protected:
    Storage _figures;
};

#endif // FIGURE_H
