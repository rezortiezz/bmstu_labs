#include <cmath>

double f(double x)
{
    return x - cos(x); // -1 <= cos(x) <= 1 => -1 <= x <= 1
}

double f1(double x)
{
    return x - 10*cos(x);  // -10 <= 10*cos(x) <= 10 => -10 <= x <= 10
}

double f_der(double x)
{
    return 1 + sin(x);  // f'(x) = (x - cos(x))' = 1 + sin(x)
}

double f1_der(double x)
{
    return 1 + 10 * sin(x); //(x - 10cos(x))' = 1 + 10sin(x)
}
