#include <stdio.h>
#include <math.h>

int ex1(int m, int n)
{
    int counter = 0;
     
    for (int i = 1; i <= n; i++)
    {
        (i % 5 == 0 && i % m != 0) ? counter++ : 0;
    }

    return counter;
}

long int ex2(int a)
{
    long int  ans = 1;

    if (a >= 0)
    {
        for (int i = 2; i <= 8; i++)
        {
            ans *= (i*i - a); 
        }
    } else {
        for (int i = 3; i <= 9; i++)
        {
            ans *= i - 2;
        }
    }

    return ans;
}

double sinx_taylor(double n)
{
    double sum = 0.0;
    int i = 1;

}

int main()
{
    /*int m, n;
    scanf("%d %d", &n, &m);
    printf("ex1:\t%d\n", ex1(m, n));

    int a;
    scanf("%d", &a);
    printf("ex2:\t%d", ex2(a));*/

    printf("x\tY(x)\tS(x)\tN\n");
    for (double x = 0; x <= 1; x += 0.2)
    {
        printf("%1.2f\t%1.3f\t0\t0\n", x, sin(x));
    }
    
    return 0;
}
