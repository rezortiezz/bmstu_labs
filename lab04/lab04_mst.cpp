#include <iostream>

#include "functions.h"
#include "methods.h"

#define EPS1 1e-6
#define EPS2 1e-8

int main()
{
    std::cout << "EPSILON: " << EPS1 << std::endl;
    iterative(f, EPS1, -1.0, 1);
    binary_search(f, EPS1, -1.0, 1.0, 1);
    newtons(f, f_der, EPS1, -1.0, 1);
    
    std::cout << "\nEPSILON: " << EPS2 << std::endl;
    iterative(f, EPS2, -1.0, 1);
    binary_search(f, EPS2, -1.0, 1.0, 1);
    newtons(f, f_der, EPS2, -1.0, 1);

    std::cout << "\nf(x) = x - 10*cos(x)\n";
    iterative(f, EPS1, -5.0, 10);
    binary_search(f, EPS1, -3.0, 3.0, 10);
    newtons(f, f_der, EPS1, -3.0, 10);

    return 0;
}
