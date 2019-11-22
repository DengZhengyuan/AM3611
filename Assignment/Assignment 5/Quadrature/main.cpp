#include <iostream>
#include <fstream>
#include <cmath>
#include "LeftRiemann.h"
#include "RightRiemann.h"
#include "Midpoint.h"
#include "Trapezoid.h"
#include "Simpsons.h"
#include <string>

double input_function(double x);
double input_function_2(double x);
void write_result(const std::string& name,
                  int subintervals,
                  double ex,
                  double (*ff)(double x),
                  double a,
                  double b);

/* ---------------------------------------------------- */
/*                     Main Function                    */
/* ---------------------------------------------------- */
int main(int argc, char * argv[]) {
    int nodes[10] = {4, 10, 24, 50, 100, 250, 500, 1000, 5000, 10000};

    double exact_result_1, exact_result_2;
    exact_result_1 = 2*exp(2) + 38*exp(-2);
    exact_result_2 = erf(1);

    std::fstream write_head("result_1.dat");
    assert(write_head.is_open());
    write_head << "N err_left err_right err_midpoint "
                  "err_trapezoid err_Simpsons"
               << "\n";
    write_head.close();

    for (int node : nodes) {
        write_result("result_1.dat",
                      node,
                      exact_result_1,
                      input_function,
                      -2,
                      2);
    }

    std::fstream write_head_2("result_2.dat");
    assert(write_head_2.is_open());
    write_head_2 << "N err_left err_right err_midpoint "
                    "err_trapezoid err_Simpsons"
                 << "\n";
    write_head_2.close();

    for (int node : nodes) {
        write_result("result_2.dat",
                     node,
                     exact_result_2,
                     input_function_2,
                     0,
                     1);
    }

    return 0;
}

double input_function(double x) {
    return pow(x, 3)*exp(x);
}

double input_function_2(double x) {
    return 2*exp(-pow(x,2))/sqrt(M_PI);
}

void write_result(const std::string& name,
                  int subintervals,
                  double ex,
                  double (*ff)(double x),
                  double a,
                  double b) {
    LeftRiemann test1(a, b, subintervals);
    test1.fi_values(ff);

    RightRiemann test2(a, b, subintervals);
    test2.fi_values(ff);

    Midpoint test3(a, b, subintervals);
    test3.fi_values(ff);

    Trapezoid test4(a, b, subintervals);
    test4.fi_values(ff);

    Simpsons test5(a, b, subintervals);
    test5.fi_values(ff);

    std::ofstream write_data(name, std::ios::app);
    write_data.setf(std::ios::scientific);
    write_data.precision(12);

    write_data << subintervals << " "
               << abs(test1.integral()-ex) << " "
               << abs(test2.integral()-ex) << " "
               << abs(test3.integral()-ex) << " "
               << abs(test4.integral()-ex) << " "
               << abs(test5.integral()-ex) << "\n";
    write_data.close();
}