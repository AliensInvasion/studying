#include <iostream>
#include <map>

#define FOR for (int i = 0; i < 10; ++i)

#define INSERT train.insert(std::make_pair(i, num));

#define SHOW std::cout << i << " ";

#define END_LINE std::cout << std::endl;

#define CHECK FOR {if (more(train[i])) SHOW} END_LINE \
FOR {if (less(train[i])) SHOW} END_LINE

#define FILL FOR {std::cin >> num; sum += num; INSERT}

#define SUM std::cout << sum;


bool more (int number) {
    if (number > 20) return true;
    return false;
}

bool less (int number) {
    if (number < 20) return true;
    return false;
}

int main() {

    std::map<int, int> train;
    int num;
    int sum = 0;

    FILL

    CHECK

    SUM
}
