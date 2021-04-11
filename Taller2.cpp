#include <iostream>
#include <cmath>

using fptr = double (double, double, int); // apuntador de funcion

double f(double x);
double trapecio(double a, double b, int npart);
double simpson(double a, double b, int npart);
double rapidez (double a, double b, double m, fptr alg, int N);
double exacta (double b, double m);



int main(int argc, char *argv[]) {
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    double a = 0.0;
    double b = 4.0;
    double m = 1.25;
    int N1 = 10;
    int N2 = 1000;
    double delta_trapecio1 = std::fabs((rapidez (a, b, m, trapecio, N1) - exacta (b,m))/exacta(b,m)) ;
    double delta_trapecio2 = std::fabs((rapidez (a, b, m, trapecio, N2) - exacta (b,m))/exacta(b,m)) ;
    double delta_simpson1 = std::fabs((rapidez (a, b, m, simpson, N1) - exacta (b,m))/exacta(b,m)) ;
    double delta_simpson2 = std::fabs((rapidez (a, b, m, simpson, N2) - exacta (b,m))/exacta(b,m)) ;

    std::cout<< N1 << "\n" << "Trapecio 1" << "\n" << delta_trapecio1 << "\n" << "Simpson 1" << "\n" << delta_simpson1 << "\n";
     std::cout<< N2 << "\n" << "Trapecio 2" << "\n" << delta_trapecio2 << "\n" << "Simpson 2" << "\n" << delta_simpson2 << "\n";
    std::cout<< exacta (b,m);
    return 0;
}


double f(double x) {
    double a = ((2)*(x)*(std::sin(x)));
    return a;
}


double trapecio(double a, double b, int npart) {
    double h = (b-a)/npart;
    double result = 0.0;
    double x = 0;
    for (int ii = 1; ii < npart; ++ii) {
        x = a + ii*h;
        result += f(x);
    }
    result += 0.5*(f(a) + f(b));
    result *= h;
    return result;
}


double simpson(double a, double b, int npart)
{
    double h = (b-a)/npart;
    double result = f(a) + f(b);
    double sum1 = 0.0, sum2 = 0.0;
    for (int ii = 1; ii <= npart/2 - 1; ++ii) {
        double x = a + (2*ii)*h;
        sum1 += f(x);
    }
    for (int ii = 1; ii <= npart/2; ++ii) {
        double x = a + (2*ii-1)*h;
        sum2 += f(x);
    }
    result += 2*sum1 + 4*sum2;
    result *= h/3;
    return result;
}


double rapidez (double a, double b, double m, fptr alg, int N)
{
  double V = std::sqrt((((2)*(alg(a, b, N)))/(m)));
  return V;
}

double exacta (double b, double m)
{
  double x = (-b)*std::cos(b);
  double y = std::sin(b);
  double V = std::sqrt(((4*(x+y))/m)); 
  return V;
}