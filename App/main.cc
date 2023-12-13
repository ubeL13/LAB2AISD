#include <iostream>
#include <cstdlib>
#include <Node.h>

int main() {
    LinkedList<double> polynomial;
    polynomial.push_tail(2.0, 2);  // x^2
    polynomial.push_tail(-3.0, 1); // -3x
    polynomial.push_tail(1.0, 0);  // 1

    double x = 2.5;
    double result = polynomial.evaluate(x);
    std::cout << "The value of the polynomial at x = " << x << " is: " << result << std::endl;

    return 0;
}