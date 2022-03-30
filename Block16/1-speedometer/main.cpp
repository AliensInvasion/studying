#include <iostream>
#include <cstdio>


int main() {
    float speed = .0f;
    float delta = .0f;
    char speedometer[20];
    bool inMotion = false;

    do {
        std::cout << "\nEnter speed delta:\n";
        std::cin >> delta;
        std::cin.clear();
        std::cout << std::endl;

        speed += delta;

        if (speed >= .01f) {
            inMotion = true;
        }

        if (speed >= 150.f) {
            speed = 150.f;
        }

        if (speed < .01f) {
            speed = .0f;
        }

        std::sprintf(speedometer, "Speed: %.1fkm/h", speed);
        std::cout << speedometer << std::endl;

    } while (!(speed < .01f && inMotion));

    std::cout << "The car stopped." << std::endl;

}
