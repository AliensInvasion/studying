#include <iostream>

bool substr(char *a, char *b) {

    int i = 0;
    int j = 0;

    while (*(a+i) != '\0') {
        if (*(a+i) == *(b+j)) {
            if (*(b+j+1) == '\0') return true;
            ++j;
        } else {
            if (*(a+i+1) == '\0') return false;
            j = 0;
        }
        ++i;
    }
    return false;
}

int main() {

    char *a = "hello world";

    char *b = "world";

    char *c = "orldw";

    std::cout << substr(a,b) << " " << substr(a,c);

}
