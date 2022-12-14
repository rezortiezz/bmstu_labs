#include <iostream>
#include <cmath>
#include <utility>

unsigned int ex1(int, int);
long double ex2(double);
std::pair<double, int> row_sum(double, double);
double row_member(int, double);
double rec_factorial(double);
double y(double);

int main(){   
    // unsigned int n, m;
    // char inp;
    // do {
    //     std::cin >> n >> m;
    //     std::cout << ex1(m, n) << std::endl;
    //     std::cout << "Продолжить работу?(y/n)" << std::endl;
    //     std::cin >> inp;
    // } while (inp != 'n');
    
    // double a; std::cin >> a;
    // std::cout << ex2(a) << std::endl;

    // double x = 0.0;
    // double delta = 0.2;
    // double eps = 1e-6;
    // std::pair<double, int> temp;
    // std::cout << "x\t\tY(x)\t\t\tS(x)\t\t\tN\n\n";
    // for (;x <= 1; x += delta)
    // {
    //     temp = row_sum(x, eps);
    //     printf("%1.1f\t\t%1.6f\t\t%1.6f\t\t%d\n", x, y(x), temp.first, temp.second);
    // } 

    unsigned int n;
    while (true) {
        std::cin >> n;
        double cur = 0;
        for (double i = n; i > 0; i--)
        {
            cur = 1/(cur + (2*i + 1));
            if (i == 3 || i == 5 || i == 10)
            {
                printf("i: %1.0f cur: %1.10f\n", i, cur);
            }
        }
        std::cout << "res: " << cur << std::endl;
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

long double ex2(double a)
{
    long double s = 1;
    if (a >= 0) {
        for (double i = 2.0; i <= 8.0; i+= 2.0) s *= i * i;
        return s - a;
    }
    else {
        for (double i = 3.0; i<= 9.0; i+=3.0) s *= (i - 2);
        return s;
    }
}

double rec_factorial(double r) { return (r > 1) ? r * rec_factorial(r - 1) : 1;}

double row_member(int n, double x){ return ((2 * n + 1)/rec_factorial(n)) * pow(x, 2*n);}

double y(double x) { return (1 + 2 * x * x) * exp(x * x);}

std::pair<double, int> row_sum(double x, double eps) {
    double sum = 1, current_member = 1;
    std::pair<double, int> returnable;
    int n = 1;
    for (; current_member > eps; n++)
    {
        current_member = row_member(n, x);  
        sum += current_member;
    }
    returnable.first = sum;
    returnable.second = n;
    return returnable;
}