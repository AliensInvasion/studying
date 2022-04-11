#include <iostream>
#include <fstream>
#include <vector>

int main()
{

    std::vector<std::string> name;
    std::vector<std::string> surname;
    std::vector<int> debt;
    std::vector<std::string> date;
    
    int sum = 0;
    int maxDebt = 0;
    int maxDebtIndex = 0;

    std::string line;
    std::fstream sheet;

    sheet.open("..\\resources\\sheet.txt");

    for (int i = 0; !sheet.eof(); ++i) {

        std::string part1;
        std::string part2;
        int part3;
        std::string part4;

        sheet >> part1 >> part2 >> part3 >> part4;

        name.push_back(part1);
        surname.push_back(part2);
        debt.push_back(part3);
        date.push_back(part4);

    }

    sheet.close();

    for (int i = 0; i < name.size() && (name[i].length() > 0); ++i) {
        sum += debt[i];
        if (debt[i] > maxDebt) {
            maxDebt = debt[i];
            maxDebtIndex = i;
        }
    }

    std::cout << "Debt overall = " << sum << std::endl;
    std::cout << name[maxDebtIndex] << " " << surname[maxDebtIndex];
    std::cout << " has the largest amount of debt." << std::endl;

}
