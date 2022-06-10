#include <iostream>

class Window {

    int x = 1;
    int y = 1;
    int width = 1;
    int height = 1;

    friend class Screen;
};

class Screen {

    Window window;
    int width = 80;
    int height = 50;

public:

    void move() {
        int x, y;
        std::cout << "Enter the vector to move:" << std::endl;
        std::cin >> x >> y;
        if (x + window.x < 0 || x + window.x > width || y + window.y < 0 || y + window.y > height) {
            std::cout << "Error! Can't move window to destination." << std::endl;
            return;
        }
        window.x += x;
        window.y += y;
        std::cout << "New window coords: " << window.x << ", " << window.y << std::endl;
    }

    void resize() {
        int x, y;
        std::cout << "Enter window size:" << std::endl;
        std::cin >> window.width >> window.height;
        std::cout << "New window size: " << window.width << "x" << window.height << std::endl;
    }

    void display() {
        for (int i = 1; i <= height; ++i) {
            for (int j = 1; j <= width; ++j) {
                if (j >= window.x && j < window.x + window.width && i >= window.y && i < window.y + window.height){
                    std::cout << "1";
                } else std::cout << "0";
            }
            std::cout << std::endl;
        }
    }
};

int main() {


    Screen *screen = new Screen();

    std::string request;

    do {
        std::cout << "Enter request: " << std::endl;
        std::cin >> request;
        if (request == "move") {
            screen->move();
        }
        if (request == "resize") {
            screen->resize();
        }
        if (request == "display") {
            screen->display();
        }
    } while (request != "close");

    delete screen;

}