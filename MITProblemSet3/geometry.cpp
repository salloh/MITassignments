#include "geometry.h"
#include <cmath>

PointArray::PointArray()
{
    size = 0;
    points = new Point[0];
}

PointArray::PointArray(const Point ptsToCopy[], const int copySize)
{
    size = copySize;
    points = new Point[size];
    for(int i = 0; i < size; ++i) {
        points[i] = ptsToCopy[i];
    }
}

PointArray::PointArray(const PointArray& pv)
{
    size = pv.size;
    points = new Point[size];
    for(int i = 0; i < size; ++i) {
        points[i] = pv.points[i];
    }
}

PointArray::~PointArray()
{
    delete [] points;
}

void PointArray::resize(int newSize)
{
    Point* newPoints = new Point[newSize];
    int minSize = (newSize > size ? size: newSize);
    for(int i = 0; i < minSize; ++i) {
        newPoints[i] = points[i];
    }

    delete[] points;
    size = newSize;
    points = newPoints;
}

void PointArray::clear()
{
    resize(0);
}

void PointArray::push_back(const Point& p)
{
    resize(size+1);
    points[size-1] = p;
}

void PointArray::insert(const int position, const Point& p)
{
    if(position < 0 || position > size) {
        std::cout<< "Invalid Position " << std::endl;
        std::exit(1);
    }
    resize(size+1);
    for(int i = size - 1; i > position; --i) {
        points[i] = points[i-1];
    }

    points[position] = p;
}

void PointArray::remove(const int position)
{
    if(position < 0 || position >= size) {
        std::cout<< "Invalid Position " << std::endl;
        std::exit(1);
    }

    for(int i = position; i <= size-2; ++i) {
        points[i] = points[i+1];
    }
    resize(size-1);
}
Point* PointArray::get(const int position)
{
    if(position >= 0 && position <= size)
    {
        return &points[position];
    }

    return nullptr;
}

const Point* PointArray::get(const int position) const
{
    if(position >= 0 && position <= size)
    {
        return &points[position];
    }

    return nullptr;
}

int Polygon::numPolygons = 0;

Polygon::Polygon(const Point pa[], const int numPoints) : points(pa, numPoints)
{
    ++numPolygons;
}

Polygon::Polygon(const PointArray& pa) : points(pa)
{
    ++numPolygons;
}

Point constructorPoints [4];

Point * updateConstructorPoints(const Point& p0, const Point& p1, const Point& p2, const Point& p3 = Point(0 ,0))
{
    constructorPoints[0] = p0;
    constructorPoints[1] = p1;
    constructorPoints[2] = p2;
    constructorPoints[3] = p3;
 return constructorPoints;
}

Rectangle::Rectangle(const Point& ll, const Point& uu):
    Polygon(updateConstructorPoints(ll, Point(ll.getX(), uu.getY()), uu, Point(uu.getX(), ll.getY())), 4) {}

Rectangle::Rectangle(const int a, const int b, const int c, const int d):
    Rectangle(Point(a, b), Point(c, d)){}

double Rectangle::getArea() const
{
    int length = points.get(1)->getY () - points.get(0)->getY ();
    int width = points.get (2)->getX () - points.get(1)->getX ();
    return std::abs(static_cast<double>(length * width));
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c):
    Polygon(updateConstructorPoints(a, b, c), 3) {}

double Triangle::getArea() const
{
    int dx01 = points.get(0)->getX() - points.get(1)->getX();
    int dx12 = points.get(1)->getX() - points.get(2)->getX();
    int dx20 = points.get(2)->getX() - points.get(0)->getX();
    int dy01 = points.get(0)->getY() - points.get(1)->getY();
    int dy12 = points.get(1)->getY() - points.get(2)->getY();
    int dy20 = points.get(2)->getY() - points.get(0)->getY();

    double a = std::sqrt(dx01 * dx01 + dy01 * dy01);
    double b = std::sqrt(dx12 * dx12 + dy12 * dy12);
    double c = std::sqrt(dx20 * dx20 + dy20 * dy20);

    double s = (a + b + c) / 2;

    return std::sqrt(s * (s-a) * (s-b) * (s-c));
}

