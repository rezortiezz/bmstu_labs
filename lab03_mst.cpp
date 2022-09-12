#include <iostream>
#include <cmath>
#include <utility>

#define ull unsigned long long

unsigned int ex1(int, int);

long int ex2(int);

std::pair<double, int> row_sum(double, double, double);
double row_member(int, double);
double rec_factorial(double);
double y(double);

double ex4(int);
double rowm_ex4(double);

int main()
{   /*int m, n;
    std::cin >> n >> m;
    ex1(m, n);

    int a; std::cin >> a;
    ex2(a);*/

    /*double x = 0.0;
    double delta = 0.2;
    double eps = 1e-6;
    std::pair<double, int> temp;
    std::cout << "x\tY(x)\tS(x)\tN\n";
    for (;x <= 1; x += delta)
    {
        temp = row_sum(x, eps, delta);
        std::cout << x << "\t" << y(x) << "\t" << temp.first << "\t" << temp.second << "\t\n";
    } */

    unsigned int n;
    while (true) {
        std::cin >> n;
        double cur = 1;
        for (int i = 1; i <= n; i++)
        {   
            cur /= rowm_ex4(i);
            if (n == 3 || n == 5 || n == 10)
            {
                printf("i: %d cur: %1.12f\n", i, cur);
            }
        }
        printf("%1.12f\n", cur);
    }


    return 0;
}

unsigned int ex1(int m, int n)
{
    int counter = 0;
    for (int i = 1; i <= n; i++)
    {
        (i % 5 == 0 && i % m != 0) ? counter += i : counter += 0;
    }
    return counter;
}

long int ex2(int a)
{
    long int s = 1;
    if (a >= 0) {
        for (int i = 2; i <= 8; i++)
        {
            s *= i*i - a;
        }
    } else {
        for (int i = 3; i<= 9; i++)
        {
            s *= (i - 2);
        }
    }
    return s;
}

double rec_factorial(double r)
{
    return r > 1 ? r * rec_factorial(r - 1) : 1;
}

double row_member(int n, double x)
{
    return ((2 * n + 1)/rec_factorial(n)) * pow(x, 2*n);
}

std::pair<double, int> row_sum(double x, double eps, double delta) {
    double sum = 1;
    std::pair<double, int> returnable;
    unsigned int maxIterCount = 1000;
    for (int n = 1; row_member(n,x) > eps; n++)
    {
        sum += row_member(n, x);
        if (n > maxIterCount)
        {
            returnable.first = sum;
            returnable.second = n;
            return returnable;
        }
        returnable.second = n;
    }
    returnable.first = sum;
    return returnable;
    
}

double y(double x)
{
    return (1 + pow(2.0 * x, 2)) * exp(pow(x, 2.0));
}

double rowm_ex4(double n)
{
    return 2 * n + 1;
}