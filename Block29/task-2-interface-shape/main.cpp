#include <iostream>
#include <cmath>
#define PI 3.14159

struct BoundingBoxDimensions
{
    double width, height;
};

class Shape
{
public:
    virtual std::string type() = 0;
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
};

class Circle : public Shape
{
    double radius;

public:

    Circle(double inRadius) : radius(inRadius)
    {
    }

    virtual std::string type() override
    {
        return "Circle";
    }

    virtual double square() override
    {
        return (2*PI*radius);
    }

    virtual BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions box{};
        box.height = 2*radius;
        box.width = 2*radius;
        return box;
    }

};

class Triangle : public Shape
{
    double sides[3];

public:

    Triangle(double a, double b, double c)
    {
        sides[0] = a;
        sides[1] = b;
        sides[2] = c;
    }

    virtual std::string type() override
    {
        return "Triangle";
    }

    virtual double square() override
    {
        double p = (sides[0]+sides[1]+sides[2])/2;
        return sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
    }

    virtual BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions box{};
        double p = (sides[0]+sides[1]+sides[2])/2;
        double radius = (sides[0]*sides[1]*sides[2])/(4*(sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]))));
        box.width = 2*radius;
        box.height = 2*radius;
        return box;
    }

};

class Rectangle : public Shape
{

    double width, height;

public:

    Rectangle(double inWidth, double inHeight) : width(inWidth), height(inHeight)
    {
    }

    virtual std::string type() override
    {
        return "Rectangle";
    }

    virtual double square() override
    {
        return width*height;
    }

    virtual BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions box{};
        box.width = width;
        box.height = height;
        return box;
    }

};

void printParams(Shape* shape)
{
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    std::cout << "Width: " << shape->dimensions().width << std::endl;
    std::cout << "Height: " << shape->dimensions().height << std::endl;
    std::cout << std::endl;
}

int main(){

    Circle c(5.5);
    printParams(&c);

    Triangle t(3,4,5);
    printParams(&t);

    Rectangle r(4, 6);
    printParams(&r);

}
