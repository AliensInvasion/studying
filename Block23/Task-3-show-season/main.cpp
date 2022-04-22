#include <iostream>

#define SPRING 1
#define SUMMER 0
#define AUTUMN 0
#define WINTER 0
#define SHOW(string) int main() {std::cout << string;}

#if SPRING

SHOW("Spring")

#endif

#if SUMMER

SHOW("Summer")

#endif

#if AUTUMN

SHOW("Autumn")

#endif

#if WINTER

SHOW("Winter")

#endif



