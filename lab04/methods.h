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
