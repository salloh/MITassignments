#ifndef POINT_H
#define POINT_H

#include<cstdlib>
#include<iostream>

class Point {
private:
    int xCordinate;
    int yCordinate;
public:
    Point(int x = 0, int y = 0): xCordinate{x}, yCordinate(y){}
    int getX() const {return xCordinate;}
    int getY() const {return yCordinate;}
    void setX(const int x) {xCordinate = x;}
    void setY(const int x) {xCordinate = x;}
};


class PointArray {
private:
    int size;
    Point * points;
    void resize (int size);
public:
    PointArray();
    PointArray(const Point points[], const int size);
    PointArray(const PointArray& pv);
    ~PointArray();

    void push_back(const Point& p);
    void insert(const int position, const Point& p);
    void remove(const int position);
    const int getSize() const {return size;};
    void clear();
    Point* get(const int position);
    const Point* get(const int position) const;
};

class Polygon {
protected:
    static int numPolygons;
    PointArray points;
public:
    Polygon(const Point points[], const int numPoints);
    Polygon(const PointArray& pa);
    virtual double getArea() const = 0;
    static int getNumPolygon() {return numPolygons;}
    int getNumSides() const {return points.getSize();}
    const PointArray* getPoints() const {return &points;}
    ~Polygon() {--numPolygons;}
};

class Rectangle: public Polygon {
public:
    Rectangle(const Point& a, const Point& b);
    Rectangle(const int a, const int b, const int c, const int d);
    double getArea() const;
};

class Triangle: public Polygon {
public:
    Triangle(const Point& a, const Point& b, const Point& c);
    double getArea() const;
};
#endif // POINT_H
