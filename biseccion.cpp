
#include <iostream>
#include <cstdlib>
#include <cmath>

using fptr = double (double, double);


const double G = 9.81;
const double VT = 40;
const double T = 10;

double f(double x, double M);
double bisection(double xl, double xu, double eps, fptr fun, int & nsteps, double M);


int main (int argc, char *argv[])
{
    double XL = std::atof(argv[1]);
    double XU = std::atof(argv[2]);
    double eps = std::atof(argv[3]);
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    int steps = 0;
   for (double M = 60; M <= 110; M = M + 5 )
   {
     double root = bisection(XL, XU, eps, f, steps, M);
    std::cout << M << "\t" << root << "\t" << f(root, M) << "\t" << steps << "\n";
   } //creo un for para que me vaya variando M
    
	return 0;
}

double f(double x, double M)
{
    return M*G*(1 - std::exp(-x*T/M))/x - VT;
}

double bisection(double xl, double xu, double eps, fptr fun, int & nsteps, double M)
{
    nsteps = 0; //se refiere a cuantas veces tuvo que realizar el proceso hasta encontrar la precision exigida
    double xr = 0.5*(xl + xu);
    while (1) {
        xr = 0.5*(xl + xu);
        nsteps++;
        //std::cout << xr << "\n";
        if (std::fabs(fun(xr, M)) < eps) {
            break;
        } else if (fun(xl, M)*fun(xr, M) < 0) {
            xu = xr;
        } else {
            xl = xr;
        }
        //std::cout << xl << "\t" << xu << "\n";
    }
    return xr;
}
