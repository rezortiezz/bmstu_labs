#include <cmath>

double f(double x, int k)
{
    return x - k * cos(x); // -1 <= cos(x) <= 1 => -1 <= x <= 1
}

double f_der(double x, int k)
{
    return 1 + k * sin(x);  // f'(x) = (x - cos(x))' = 1 +  k *sin(x)
}

