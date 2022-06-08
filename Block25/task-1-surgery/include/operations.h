#include "point.h"

int tweezers(Point &first) {
    std::cout << "Tweezers used in point";
    showPoint(first);
}

int hemostat(Point &first) {
    std::cout << "Hemostat used in point";
    showPoint(first);
}

bool suture(Point &first, Point &second, Point &firstSuture, Point &secondSuture) {
    std::cout << "Suture made from";
    showPoint(first);
    std::cout << " to";
    showPoint(second);
}

int scalpel(Point &first, Point &second) {
    std::cout << "Incision made from";
    showPoint(first);
    std::cout << " to";
    showPoint(second);
}