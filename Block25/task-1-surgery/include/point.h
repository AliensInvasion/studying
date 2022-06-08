#include <iostream>

struct Point
{
    double x, y;
};

Point pointGet() {
    Point point{};
    std::cout << "Enter the coordinates of point:" << std::endl;
    std::cin >> point.x >> point.y;
    return point;
}

void showPoint(Point point) {
    std::cout << " [" << point.x << ", " << point.y << "]";
}

bool comparePoints(Point &first, Point &second, Point &firstSuture, Point &secondSuture) {
    bool good = true;
    if (first.x != firstSuture.x || first.y != firstSuture.y) good = false;
    if (second.x != secondSuture.x || second.y != secondSuture.y) good = false;
    return good;
}