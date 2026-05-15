#include <iostream>

using namespace std;

double square(double x) { return x * x; }

void print_square(double x) {
  cout << "the square of " << x << " is " << square(x) << "\n";
  // cout << format("the square of {:.2f} is {:.2f} \n", x, square(x));
}

int main() { print_square(1.234); }
