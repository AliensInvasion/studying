#include "operations.h"
#define GET_REQUEST std::cout << std::endl << "Enter request:" << std::endl; std::cin >> request;

int main() {

    std::string request;
    GET_REQUEST
    while (request != "scalpel") {
        GET_REQUEST
    }
    Point first = pointGet();
    Point second = pointGet();
    scalpel(first, second);
    while (true) {
        GET_REQUEST
        if (request == "hemostat") {
            Point current = pointGet();
            hemostat(current);
        }
        if (request == "tweezers") {
            Point current = pointGet();
            tweezers(current);
        }
        if (request == "suture") {
            Point firstSuture = pointGet();
            Point secondSuture = pointGet();
            if (!comparePoints(first, second, firstSuture, secondSuture)) {
                std::cout << "Not correct points." << std::endl;
            } else {
                suture(first, second, firstSuture, secondSuture);
                break;
            }
        }
    }
    return 0;
}
