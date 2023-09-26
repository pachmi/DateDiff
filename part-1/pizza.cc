// X: add a header
// Daniel Thibault
// daniel.thibault@csu.fullerton.edu
// @JustDanielThanks
// @pachmi

#include <iostream>

// Given the diameter and price of a pizza, calculate the unit price, which is
// the number of dollars per square inch.
double PizzaUnitPrice(double diameter, double price) {
  // X: write statements to implement this function, and delete this comment
  double radius{diameter / 2.0};
  const double kpi{3.1415926};
  double area{kpi * (radius * radius)};
  double unit_price{price / area};
  return unit_price;  // X: replace this return statement with one that actually
                      // works
}

int main(int argc, char* argv[]) {
  // X: Declare a variable to hold pizza diameter;
  // print the prompt "Enter pizza diameter in inches: "; and
  // input a number from standard input into the variable.
  double pizza_diameter{0.0};
  std::cout << "Enter pizza diameter in inches: ";
  std::cin >> pizza_diameter;
  // X: Declare a variable to hold pizza price;
  // print the prompt "Enter pizza price in dollars: "; and
  // input a number from standard input into the variable.
  double pizza_price{0.0};
  std::cout << "Enter pizza priced in dollars: ";
  std::cin >> pizza_price;
  // X: Declare a variable to hold unit price;
  // initialize the variable with the value returned from a call to the
  // PizzaUnitPrice function above.
  double unit_price{PizzaUnitPrice(pizza_diameter, pizza_price)};
  // X: Print out "Unit price = ";
  // then the unit price variable;
  // then " dollars per square inch";
  // then a newline character.
  std::cout << "Unit price = " << unit_price << " dollars per square inch.\n";
  return 0;
}
