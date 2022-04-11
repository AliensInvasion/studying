#include <iostream>
#include <fstream>

bool isPng(const char *c){
    if (*c == -119 && *(c+1) == 80 && *(c+2) == 78 && *(c+3) == 71) return true;
    else return false;
}

int main() {

    char buffer[4];

    std::ifstream file;
    std::string ext = ".png";
    std::string path = "..\\resources\\real.png";

    int offset = (int)path.length()-4;

    file.open(path, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Error! Destination file does not exist!";
        return 1;
    }

    for (char & i : buffer) {
        file >> i;
    }

    if (isPng(buffer) && path.substr(offset, 4) == ext) {
        std::cout << "This is PNG file." << std::endl;
    }
    else std::cout << "This is NOT PNG file." << std::endl;

}
