#include <iostream>
#include <cmath>
#include <map>

enum Color
{
    NONE,
    RED,
    BLUE,
    GREEN
};

std::map<Color, std::string> colorDict
{
        {NONE,  "no color"},
        {RED,   "red"},
        {GREEN, "green"},
        {BLUE,  "blue"},
};

class Figure
{
    double x, y;
    Color color;

public:

    Figure(double &inX, double &inY, Color &inColor) : x(inX), y(inY), color(inColor){}

    void getCircumscribingRectangle(double first, double second)
    {
        std::cout << "Circumscribing rectangle coords: " << std::endl;
        std::cout << "[" << x - first << "," << y - second << "] ";
        std::cout << "[" << x - first << "," << y + second << "] ";
        std::cout << "[" << x + first << "," << y + second << "] ";
        std::cout << "[" << x + first << "," << y - second << "] ";
        std::cout << std::endl;
    }

    std::string getColor() const
    {
        return colorDict.at(color);
    }

};

class Circle : Figure
{
    double radius;

public:

    Circle(double &inX, double &inY, Color &inColor, double &inRadius) :
            Figure(inX, inY, inColor), radius(inRadius) {}

    void color()
    {
        std::cout << "Color is: " << getColor() << std::endl;
    }

    void circumscribingRectangle()
    {
        getCircumscribingRectangle(radius, radius);
    }

    void getArea()
    {
        std::cout << "Area of circle = " << atan(1) * 4 * radius << std::endl;
    }

};

class Triangle : Figure
{
    double length;

public:

    Triangle(double &inX, double &inY, Color &inColor, double &inLength) :
            Figure(inX, inY, inColor), length(inLength) {}

    void color()
    {
        std::cout << "Color is: " << getColor() << std::endl;
    }

    void circumscribingRectangle()
    {
        getCircumscribingRectangle(length/2, length/2);
    }

    double getArea()
    {
        std::cout << "Area of triangle = " << std::sqrt(3) / 4 << std::endl;
    }

};

class Square : Figure
{
    double length;

public:

    Square(double &inX, double &inY, Color &inColor, double &inLength) :
            Figure(inX, inY, inColor), length(inLength) {}

    void color()
    {
        std::cout << "Color is: " << getColor() << std::endl;
    }

    void circumscribingRectangle()
    {
        getCircumscribingRectangle(length/2, length/2);
    }

    double getArea()
    {
        std::cout << "Area of square = " << length * length << std::endl;
    }
};

class Rectangle : Figure
{
    double width, height;

public:

    Rectangle(double &inX, double &inY, Color &inColor, double &inWidth, double &inHeight) :
            Figure(inX, inY, inColor), width(inWidth), height(inHeight) {}

    void color()
    {
        std::cout << "Color is: " << getColor() << std::endl;
    }

    void circumscribingRectangle()
    {
        getCircumscribingRectangle(width/2, height/2);
    }

    void getArea()
    {
        std::cout << "Area of rectangle = " << width * height << std::endl;
    }
};

int main(){
    std::string request;
    do {
        std::cout << "Enter request:" << std::endl;
        std::cin >> request;

        Color color = NONE;
        double x, y;

        if (request == "circle" || request == "square" || request == "triangle" || request == "rectangle")
        {
            std::string inColor;
            std::cout << "Enter center point coords:" << std::endl;
            std::cin >> x >> y;
            std::cout << "Enter the color of object:" << std::endl;
            std::cin >> inColor;
            if (inColor == "red") color = RED;
            if (inColor == "blue") color = BLUE;
            if (inColor == "green") color = GREEN;
        }

        if (request == "circle") {
            std::cout << "Enter the radius of circle:" << std::endl;
            double radius;
            std::cin >> radius;
            auto *circle = new Circle(x, y, color, radius);
            circle->color();
            circle->getArea();
            circle->circumscribingRectangle();
            delete circle;
        }
        if (request == "square") {
            std::cout << "Enter the side of square:" << std::endl;
            double length;
            std::cin >> length;
            auto *square = new Square(x, y, color, length);
            square->color();
            square->getArea();
            square->circumscribingRectangle();
            delete square;
        }
        if (request == "triangle") {
            std::cout << "Enter the side of triangle:" << std::endl;
            double length;
            std::cin >> length;
            auto *triangle = new Triangle(x, y, color, length);
            triangle->color();
            triangle->getArea();
            triangle->circumscribingRectangle();
            delete triangle;
        }
        if (request == "rectangle") {
            std::cout << "Enter the width and height of rectangle:" << std::endl;
            double width, height;
            std::cin >> width >> height;
            auto *rectangle = new Rectangle(x, y, color, width, height);
            rectangle->color();
            rectangle->getArea();
            rectangle->circumscribingRectangle();
            delete rectangle;
        }
    } while (request != "exit");
}
