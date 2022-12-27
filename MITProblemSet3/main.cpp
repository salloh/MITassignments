#include "geometry.h"
#include <iostream>

void printAttributes(Polygon *p)
{
    std::cout<< "Polygon's Area is: " << p->getArea() << " sq. unit(s)\n\n";
    const PointArray* pa = p->getPoints();

    std::cout<< "Polygon's Points are: " << '\n';
    for(int i = 0; i < pa->getSize(); ++i) {
        std::cout<< '(' << pa->get(i)->getX() << ", " << pa->get(i)->getY() << ")\n";
    }
}

int main()
{
    std::cout<< "Enter Lower Left and Upper Right Point of a Rectangle: ";

    int llx, lly, uux, uuy;
    std::cin>>llx>>lly>>uux>>uuy;

    Point ll(llx, lly);
    Point uu(uux, uuy);

    Rectangle R(ll, uu);
    printAttributes(&R);

    std::cout<< "Enter 3 Co-ordinates of a Triangle: ";
    int x1, y1, x2, y2, x3, y3;
    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;

    Point a(x1, y1);
    Point b(x2, y2);
    Point c(x3, y3);

    Triangle T(a, b, c);
    printAttributes(&T);

    return 0;
}
