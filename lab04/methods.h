void iterative(double (*f_cur)(double, int), double EPS, double x_0, int k)
{   
    std::cout << "iterative method: x = ";
    unsigned int counter = 0;
    while (fabs(f_cur(x_0, k)) > EPS)
    {
        counter++;
        x_0 = x_0 - f_cur(x_0, k);
    }

    std::cout << x_0 << "; number of iterations: " << counter << std::endl;
}

void binary_search(double (*f_cur)(double, int), double EPS, double lx, double rx, int k)
{
    unsigned int counter = 0;
    std::cout << "binary search method: x = ";
    double mid; //lx - left bound, rx - right bound
    while (lx != rx)
    {
        counter++;
        mid  = lx + (rx - lx)/2;
        if (fabs(f_cur(mid, k)) < EPS) 
        {
            std::cout << mid << "; number of iterations: " << counter << std::endl;
            break;
        }
        else {
            (f_cur(mid, k) * f_cur(lx, k) < 0) ? rx = mid - EPS : lx = mid + EPS; 
        }
    }
}

void newtons(double (*f_cur)(double, int), double (*f_der_cur)(double, int), double EPS, double x_0, int k)
{
    unsigned int counter = 0;
    while (fabs(f_cur(x_0, k)) > EPS)
    {
        counter++;
        x_0 = x_0 - (f_cur(x_0, k)/f_der_cur(x_0, k));
    } 
    std::cout << "Newton's method: x = " << x_0 << "; number of iterations: " << counter << std::endl;
}
