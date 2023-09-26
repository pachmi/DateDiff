
# What to Do

1. Read the entire README with your partner before doing anything else.
1. With your partner, edit the `pizza.cc` source file using VS Code. Add the required header. Replace all the TODO comments with working code. Remember, make small changes and compile often.
1. Your program must use the `PizzaUnitPrice` function. Do not change the prototype of this function (name, return type, argument types).
1. Compile your program with the `make` shell command. Use the **debug compile error** procedure to debug any compile errors.
1. Run your program with the `./pizza` shell command.
1. Test that your program passes all of the test cases in the test suite above. If your program suffers a runtime error, use the **debug runtime error** procedure to debug the error. If your program does not produce the expected output, use the **debug logic error** procedure to debug the error.
1. Check your header with the `make header` shell command. Correct any errors.
1. Check for format errors with the `make format` shell command. Correct any errors.
1. Check for lint errors with the `make lint` shell command. Correct any errors.
1. Test your program against automated test with the `make test` command. Debug any runtime errors or logic errors using the same procedures.
1. After your program passes all of these tests and checks, push your code to GitHub. Use the usual trio of commands: `git add`, `git commit`, and `git push`.

# Pizza Unit Price

Computer programmers eat a lot of pizza. Which pizzeria is the best deal? It is easy to tell whether one price is lower than another. But to get an accurate answer, we need to take the size of pizzas into account.

The [unit price](https://en.wikipedia.org/wiki/Unit_price) of a product is the sale price divided by the amount of product.
For example, if a carton of milk costs $2.19 and contains 32 ounces, then its unit price is
$2.19 \div 32 = 0.0684375$
dollars per ounce.
If a larger jug costs $3.79 and contains 128 ounces, then its unit price is
$3.79 \div 128 = .029609375$
dollars per ounce.
Even though the jug has a higher price, it is a better value because the cost of each ounce of milk is less.

Restaurants use the [diameter](https://en.wikipedia.org/wiki/Diameter) of a pizza to describe its size. The price and diameter of some representative pizzas is given below.

| Pizzeria | Diameter | Price |
|----------|----------|-------|
| [Pepz Pizza](https://www.pepzpizzaeateryca.com/) | 12 inches | $18.50 |
| [Pepz Pizza](https://www.pepzpizzaeateryca.com/) | 18 inches | $26.50 |
| [Mr Taco Nice](https://www.yelp.com/biz/mr-taco-nice-anaheim) | 14 inches | $16.99 |
| [Pizza Hut](https://www.pizzahut.com/) | 14 inches | $13.99 |

To make accurate comparisons, we should calculate the unit price of a pizza from its **area**, not its diameter. An 18-inch pizza is quite a lot more food than a 14-inch pizza.

<img
 alt="image of a circle, diameter, and radius"
 src="https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/parts-of-a-2d-circle-1-1624375522.png"
 width=500>

The [area of a circle](https://www.cuemath.com/geometry/area-of-a-circle/) is $$\pi r^2,$$ where $\pi \approx 3.1415926$ and $r$ is the radius of the circle. A circle's radius is one half of its diameter. The notation $r^2$ means $r$ raised to the second power, which is equal to $r \times r.$

Putting this all together, if a pizza has diameter $d$ and price $p,$ then its unit price is
$$p \div [\pi (d \div 2)^2]$$ dollars per square inch.

## Requirements

Your program should prompt the user for the diameter and price of a pizza; use a function to calculate the unit price of the pizza; and print that unit price to standard output.

You shall use [std::cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal and you shall use [std::cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section _Example Input and Output_ below.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:

* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.

## Functions

The main goal of this exercise is for you to practice writing a function definition. The starter code has one function that you need to complete.

### PizzaUnitPrice

```C++
// Given the diameter and price of a pizza, calculate the unit price, which is
// the number of dollars per square inch.
double PizzaUnitPrice(double diameter, double price)
```

### main

As usual, you need to complete the program's `main` function.

## Example Input and Output

The input and output of your program should match the following.

```
$ ls
check_formatting  Makefile  pizza.cc  README.md
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++17 -D LINUX -D AMD64 pizza.cc \
| sed 's/\(pizza\)\.o[ :]*/\1.o pizza.d : /g' > pizza.d; \
[ -s pizza.d ] || rm -f pizza.d
clang++ -g -O3 -Wall -pipe -std=c++17 -D LINUX -D AMD64 -c pizza.cc
clang++ -g -O3 -Wall -pipe -std=c++17 -o pizza pizza.o
$ ./pizza
Enter pizza diameter in inches: 12
Enter pizza price in dollars: 18.50
Unit price = 0.163576 dollars per square inch
$ ./pizza
Enter pizza diameter in inches: 14
Enter pizza price in dollars: 16.99
Unit price = 0.110369 dollars per square inch
$ 
```

## Test Cases

Test your program before moving on. For each of the test cases below,

1. Look at the test suite, and identify the first test case, its input, and expected output.
1. Run your program with `./pizza` .
1. Provide the program with the test case input.
1. If the program crashes, use the **debug runtime error** flowchart to debug the error.
1. Observe the program output and decide whether the actual output matches the expected output.
1. If the output **does not match**, declare that the program fails the test. Use the **debug logic error** flowchart to debug the error.
1. Otherwise (the output **does match**), repeat step 2 with the next test case.

If the program works correctly (meaning no runtime or logic errors) for every test case, declare that the program passes the test. You can move on to releasing your code for part 1.

| Test Case | Input             | Expected Output                                 |
|-----------|-------------------|-------------------------------------------------|
| 1         | 12, 18.50         | `Unit price = 0.163576 dollars per square inch` |
| 2         | 18, 26.50         | `Unit price = 0.104138 dollars per square inch` |
| 3         | 14, 16.99         | `Unit price = 0.110369 dollars per square inch` |
| 4         | 14, 13.99         | `Unit price = 0.090881 dollars per square inch` |

## Next Steps

After you have pushed your code, move on to part 2.
