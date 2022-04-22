#include <iostream>

#define DAY_1 "MONDAY"
#define DAY_2 "THURSDAY"
#define DAY_3 "WEDNESDAY"
#define DAY_4 "THURSDAY"
#define DAY_5 "FRIDAY"
#define DAY_6 "SATURDAY"
#define DAY_7 "SUNDAY"

#define DAY(num) printf("%s", DAY_ ## num);

int main() {
    int num;
    std::cin >> num;
    if (num == 1) DAY(1)
    if (num == 2) DAY(2)
    if (num == 3) DAY(3)
    if (num == 4) DAY(4)
    if (num == 5) DAY(5)
    if (num == 6) DAY(6)
    if (num == 7) DAY(7)
}
