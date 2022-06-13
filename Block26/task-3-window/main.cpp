#include <iostream>

class Window {

    int x = 1;
    int y = 1;
    int width = 1;
    int height = 1;

public:

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    void resizeWindow(int &w, int &h) {
        width = w;
        height = h;
    }

    void moveWindow(int &vecX, int &vecY) {
        x += vecX;
        y += vecY;
    }

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
        if (x + window.getX() < 0 || x + window.getX() > width || y + window.getY() < 0 || y + window.getY() > height) {
            std::cout << "Error! Can't move window to destination." << std::endl;
            return;
        }
        window.moveWindow(x, y);
        std::cout << "New window coords: " << window.getX() << ", " << window.getY() << std::endl;
    }

    void resize() {
        int x, y;
        std::cout << "Enter window size:" << std::endl;
        std::cin >> x >> y;
        window.resizeWindow(x, y);
        std::cout << "New window size: " << window.getWidth() << "x" << window.getHeight() << std::endl;
    }

    void display() {
        for (int i = 1; i <= height; ++i) {
            for (int j = 1; j <= width; ++j) {
                if (j >= window.getX() && j < window.getX() + window.getWidth() && i >= window.getY() && i < window.getY() + window.getHeight()){
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