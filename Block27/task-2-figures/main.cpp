#include <iostream>
#include <cmath>

enum Color
{
    NONE,
    RED,
    BLUE,
    GREEN
};

class Figure
{
    double x, y;
    Color color;

public:

    void getCircumscribingRectangle(double first, double second)
    {
        std::cout << "Circumscribing rectangle coords: " << std::endl;
        std::cout << "[" << x - first << "," << y - second << "] ";
        std::cout << "[" << x - first << "," << y + second << "] ";
        std::cout << "[" << x + first << "," << y + second << "] ";
        std::cout << "[" << x + first << "," << y - second << "] ";
        std::cout << std::endl;
    }

    std::string getColor()
    {
        if (color == RED) return "red";
        if (color == BLUE) return "blue";
        if (color == GREEN) return "green";
        return "no color";
    }

    Figure()
    {
        std::string inColor;
        color = NONE;
        std::cout << "Enter center point coords:" << std::endl;
        std::cin >> x >> y;
        std::cout << "Enter the color of object:" << std::endl;
        std::cin >> inColor;
        if (inColor == "red") color = RED;
        if (inColor == "blue") color = BLUE;
        if (inColor == "green") color = GREEN;
    }
};

class Circle : Figure
{
    double radius;

public:

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

    Circle()
    {
        std::cout << "Enter the radius of circle:" << std::endl;
        std::cin >> radius;
    }
};

class Triangle : Figure
{
    double length;

public:

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

    Triangle()
    {
        std::cout << "Enter the side of triangle:" << std::endl;
        std::cin >> length;
    }
};

class Square : Figure
{
    double length;

public:

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

    Square()
    {
        std::cout << "Enter the side of square:" << std::endl;
        std::cin >> length;
    }
};

class Rectangle : Figure
{
    double width, height;

public:

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

    Rectangle()
    {
        std::cout << "Enter the width and height of rectangle:" << std::endl;
        std::cin >> width >> height;
    }
};

int main(){
    std::string request;
    do {
        std::cout << "Enter request:" << std::endl;
        std::cin >> request;
        if (request == "circle") {
            Circle *circle = new Circle();
            circle->color();
            circle->getArea();
            circle->circumscribingRectangle();
            delete circle;
        }
        if (request == "square") {
            Square *square = new Square();
            square->color();
            square->getArea();
            square->circumscribingRectangle();
            delete square;
        }
        if (request == "triangle") {
            Triangle *triangle = new Triangle();
            triangle->color();
            triangle->getArea();
            triangle->circumscribingRectangle();
            delete triangle;
        }
        if (request == "rectangle") {
            Rectangle *rectangle = new Rectangle();
            rectangle->color();
            rectangle->getArea();
            rectangle->circumscribingRectangle();
            delete rectangle;
        }
    } while (request != "exit");
}
