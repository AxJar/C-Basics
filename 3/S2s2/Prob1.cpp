#include "Prob1.h"
#include <iostream>

int Prob1::proba(int n, int* ptr)
{
    if (n <= 0) {

        //*ptr = *ptr + 1;
        //std::cout << *ptr << std::endl;
        return 400;

    }
    else {
        *ptr = *ptr + 1;
        std::cout << *ptr << std::endl;
        return Prob1::proba(n - 2, ptr) +
        Prob1::proba(n - 2, ptr) +
        Prob1::proba(n - 2, ptr) +
        Prob1::proba(n - 2, ptr);
    }

}

int Prob1::probc(int n, int*ptr)
{
    if (n == 0) {

        //*ptr = *ptr + 1;
        //std::cout << *ptr << std::endl;
        return 400;

    }
    else {
        *ptr = *ptr + 1;
        std::cout << *ptr << std::endl;
        return Prob1::probc(n / 2, ptr) +
        Prob1::probc(n / 2, ptr) +
        Prob1::probc(n / 2, ptr) +
        Prob1::probc(n / 2, ptr);
    }

}
