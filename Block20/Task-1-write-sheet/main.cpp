#include <iostream>
#include <fstream>
#include <sstream>

bool isDate(std::string &str){

    if (str.length() != 10) return false;
    if (str[2] != '.' || str[5] != '.') return false;

    bool good = false;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 48 && str[i] <= 57) good = true;
        if (i == 2 || i == 5) good = true;
        if (!good) return false;
        good = false;
    }

    int date, month, year;
    date = std::stoi(str.substr(0, 2));
    month = std::stoi(str.substr(3, 2));
    year = std::stoi(str.substr(6, 4));

    if (date < 1 || date > 31) return false;
    if (month < 1 || month > 12) return false;
    if (year < 1900 || year > 3000) return false;

    return true;
}

bool isLetters(std::string &str){
    bool good = false;
    for (char i : str) {
        if (i >= 97 && i <= 122) good = true;
        if (i >= 65 && i <= 90) good = true;
        if (!good) return false;
        good = false;
    }
    return true;
}

bool isDigits(std::string &str){
    bool good = false;
    for (char i : str) {
        if (i >= 48 && i <= 57) good = true;
        if (!good) return false;
        good = false;
    }
    return true;
}

bool check(std::string &line){

    std::stringstream stream;
    stream << line;

    std::string name, surname, debt, date;
    stream >> name >> surname >> debt >> date;

    if (isLetters(name) && isLetters(surname) && isDigits(debt) && isDate(date)) {
        return true;
    } else return false;

}

int main()
{
    std::string line;
    std::cout << "Enter the data:" << std::endl;
    std::getline(std::cin, line);

    while (!check(line)){
        std::cout << "Something went wrong! Enter again:" << std::endl;
        std::getline(std::cin, line);
    }

    std::ofstream sheet("..\\resources\\sheet.txt", std::ios::app);
    sheet << line << std::endl;
    sheet.close();

}
