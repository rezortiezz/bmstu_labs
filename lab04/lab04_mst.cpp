#include <iostream>
#include <cmath>

#define EPS1 1e-6
#define EPS2 1e-8


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

void iterative(double (*f_cur)(double), double EPS, double x_0)
{
    std::cout << "iterative method: x = ";
    unsigned int counter = 0;
    while (fabs(f_cur(x_0)) > EPS)
    {
        counter++;
        x_0 = x_0 - f_cur(x_0);
    }

    std::cout << x_0 << "; number of iterations: " << counter << std::endl;
}

void binary_search(double (*f_cur)(double), double EPS, double lx, double rx)
{
    unsigned int counter = 0;
    std::cout << "binary search method: x = ";
    double mid; //lx - left bound, rx - right bound
    while (lx != rx)
    {
        counter++;
        mid  = lx + (rx - lx)/2;
        if (fabs(f_cur(mid)) < EPS) 
        {
            std::cout << mid << "; number of iterations: " << counter << std::endl;
            break;
        }
        else {
            (f_cur(mid) * f_cur(lx) < 0) ? rx = mid - EPS : lx = mid + EPS; 
        }
    }
}

void newtons(double (*f_cur)(double), double (*f_der_cur)(double), double EPS, double x_0)
{
    unsigned int counter = 0;
    while (fabs(f_cur(x_0)) > EPS)
    {
        counter++;
        x_0 = x_0 - (f_cur(x_0)/f_der_cur(x_0));
    } 
    std::cout << "Newton's method: x = " << x_0 << "; number of iterations: " << counter << std::endl;
}


int main()
{
    std::cout << "EPSILON: " << EPS1 << std::endl;
    iterative(f, EPS1, -1.0);
    binary_search(f, EPS1, -1.0, 1.0);
    newtons(f, f_der, EPS1, -1.0);
    
    std::cout << "\nEPSILON: " << EPS2 << std::endl;
    iterative(f, EPS2, -1.0);
    binary_search(f, EPS2, -1.0, 1.0);
    newtons(f, f_der, EPS2, -1.0);

    std::cout << "\nf(x) = x - 10*cos(x)\n";
    iterative(f1, EPS1, -5.0);
    binary_search(f1, EPS1, -3.0, 3.0);
    newtons(f1, f1_der, EPS1, -3.0);

    return 0;
}
