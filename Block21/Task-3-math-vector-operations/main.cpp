#include <iostream>
#include <cmath>

struct MathVector
{
    int x = 0;
    int y = 0;
};

void length(int mode){
    if (mode == 0) std::cout << "------\nVector length." << std::endl;
    else std::cout << "------\nVector normalize." << std::endl;
    MathVector vec;
    std::cout << "Enter the coords of the vector:" << std::endl;
    std::cin >> vec.x >> vec.y;
    double vecLength;
    vecLength = (double)sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    if (mode == 0) std::cout << "Vector length: " << vecLength << std::endl;
    else {
        std::cout << "Normalized vector:" << std::endl;
        std::cout << "[" << (double)vec.x / vecLength << ", " << (double)vec.y / vecLength << "]" << std::endl;
    }
}

void scale(){

    int scalar;
    std::cout << "------\nVector scale." << std::endl;
    MathVector vec;
    std::cout << "Enter the coords of the vector:" << std::endl;
    std::cin >> vec.x >> vec.y;
    std::cout << "Enter the scalar number:" << std::endl;
    std::cin >> scalar;
    std::cout << "Result vector:" << std::endl;
    std::cout << "[" << scalar * vec.x << ", " << scalar * vec.y << "]" << std::endl;


}

void add(int factor){

    if (factor == 1) std::cout << "------\nVector addition." << std::endl;
    else std::cout << "------\nVector subtract." << std::endl;

    MathVector vec[2];
    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter the coords of the vector " << i+1 << ":" << std::endl;
        std::cin >> vec[i].x >> vec[i].y;
    }

    MathVector result = {vec[0].x + (vec[1].x * factor), vec[0].y  + (vec[1].y * factor)};

    std::cout << "Result vector:" << std::endl;
    std::cout << "[" << result.x << ", " << result.y << "]" << std::endl;

}

bool check(std::string &str){
    bool ok = false;
    if (str == "add") ok = true;
    if (str == "subtract") ok = true;
    if (str == "scale") ok = true;
    if (str == "length") ok = true;
    if (str == "normalize") ok = true;
    return ok;
}

int main() {

    std::string str;
    std::cout << "Commands: add, subtract, scale, length, normalize" << std::endl;
    std::cout << "Enter the command:" << std::endl;
    std::cin >> str;

    while (!check(str)) {
        std::cout << "Enter the command:" << std::endl;
        std::cin >> str;
    }

    if (str == "add") add(1);
    if (str == "subtract") add(-1);
    if (str == "scale") scale();
    if (str == "length") length(0);
    if (str == "normalize") length(1);

}
