#include <iostream>

bool substr(char *a, char *b) {

    int i = 0;
    int j = 0;

    while (true) {
        if (*(a+i) == *(b+j)) {
            if (*(b+j+1) == '\0') return true;
            ++j;
        } else {
            if (*(a+i+1) == '\0') return false;
            j = 0;
        }
        ++i;
    }
}

int main() {

    char *a = "hello world";

    char *b = "ello ";

    char *c = "word";

    std::cout << substr(a,b) << " " << substr(a,c);

}
