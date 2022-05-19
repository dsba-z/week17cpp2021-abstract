# DSBA Introduction to Programming // Workshop 33
Spring semester 2021/22

# Qt Signals and Slots. Abstract classes.

This example introduces an abstract non-Qt class `Figure` and classes `Rectangle` and `Circle` that derive from it.

The idea of an abstract class is that it provides a common interface for its derived classes, but you can't create an object of an abstract class. For example, you can make a rectangle or a circle, but you can't just make an abstract geometric shape. To make a shape you have to be more specific.

The example contains code that lets you draw rectangles and circles on a widget and a button that lets you add more rectangles.

Consider the following tasks:

## Task 1. Button to add circles.

Make another button that allows you to add more circles to the drawing area. You can reuse random number generation code from rectangles.

## Task 2. Triangles.

Add triangles as another class derived from `Figure`. Make it work similarly to rectangles and circles. Triangles should have 6 attributes: 3 pairs of coordinates for each point. When adding new triangles, you can reuse the random number generation code from previous tasks.

## Task 3. Dynamic size.

Right now shapes don't resize when you resize the window. Use `painter.scale(scalex, scaley)` to scale your canvas. Save original width and height of the render area in the constructor and use them in random number generation instead of current width and height.

