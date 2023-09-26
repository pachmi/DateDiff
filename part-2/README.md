
# What to Do
1. Read the entire README with your partner before doing anything else.
1. With your partner, edit the `datediff.cc` source file using VS Code. Add the required header. Replace all the TODO comments with working code. Remember, make small changes and compile often.
1. Your program must use the `JulianDay`, `DateDifference`, and `PrintDate` functions. Do not change the prototypes of these functions (name, return type, argument types).
1. Compile your program with the `make` shell command. Use the **debug compile error** procedure to debug any compile errors.
1. Run your program with the `./datediff` shell command.
1. Test that your program passes all of the test cases in the test suite above. If your program suffers a runtime error, use the **debug runtime error** procedure to debug the error. If your program does not produce the expected output, use the **debug logic error** procedure to debug the error.
1. Check your header with the `make header` shell command. Correct any errors.
1. Check for format errors with the `make format` shell command. Correct any errors.
1. Check for lint errors with the `make lint` shell command. Correct any errors.
1. Test your program against automated test with the `make test` command. Debug any runtime errors or logic errors using the same procedures.
1. After your program passes all of these tests and checks, push your code to GitHub. Use the usual trio of commands: `git add`, `git commit`, and `git push`.

# Date Difference

How many days until your next birthday? How many days since you adopted your dog/cat/fish? Wouldn't it be great if we could quickly calculate the number of days between any two given dates!

How can this be done? If we could take a given date, say December 5, 1933, and convert it to the number of days since the epoch (beginning of time) then we could easily do date differences and sums. How do we select a specific date as our epoch? How do we account for leap years? (When exactly is the beginning of time?)

In the United States, we use a [Gregorian Calendar](https://en.wikipedia.org/wiki/Gregorian_calendar). It was introduced in 1582 and it replaced the [Julian Calendar](https://en.wikipedia.org/wiki/Julian_calendar). Our program is going to expect a date expressed as a date on a Gregorian calendar, such as January 1, 1970 [CE](https://en.wikipedia.org/wiki/Common_Era).

Thanks to [Fliegel & Van Flandern](https://dl.acm.org/doi/pdf/10.1145/364096.364097), there is a very compact formula to take a given date in the Gregorian calendar and convert it to an integer that represents the number of days since day zero. This is called a Julian Day. In their algorithm, day zero is November 24, 4713 [BCE](https://en.wikipedia.org/wiki/Common_Era)! This means that we can very easily calculate date differences from November 24, 4713 BCE to some where past the year 5,000,000 with `int` types.

With this information in hand, we can convert a given date to a Julian Day and then take the difference between the two Julian Days to know the number of days between them.

Fliegel & Van Flandern's algorithm is [restated on the Julian Day Wikipedia page](https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation) with some slight modifications. Below is a modestly modified line of code from the [US Naval Obervatory's NOVAS](https://github.com/indigo-astronomy/novas) source code which calculates a Julian Day (`int`) from a Gregorian Date, for example 1/23/2021 where 1 is the month January, 23 is the 23rd day of the month and 2021 is the year.

```C++
int month = 1;
int day = 23;
int year = 2021;
int julian_day = day - 32075 + 1461
      * (year + 4800 + (month - 14) / 12) / 4
      + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3
      * ((year + 4900 + (month - 14) / 12) / 100) / 4;
```

This is a long formula with many expressions. Before you start blaming the computer for _doing things wrong_, double check your work. Make sure you have all the operations and parentheses in the right places. A small typo can make a big difference in the result.

To help you test your work, we know that January 1, 2021 is the Julian day 2,459,216 and January 1, 1990 is the Julian day 2,447,893. The number of days between these two dates is 11,323. Additional examples are in the section _Example Input and Output_.

You can also test your work by checking how many days there are in a [year](https://en.wikipedia.org/wiki/Calendar_year). (Recall that there are 365 days in a typical year.) This means that between January 1, 2021 and January 1, 2022, there are 365 days. However, between January 1, 2020 and January 1, 2021 there are 366 days because the year 2020 is a [leap year](https://en.wikipedia.org/wiki/Leap_year.)

## Requirements

Use the Fliegel & Van Flandern's algorithm to convert two dates into Julian Days and then take the difference. Only `int` types can be used to perform the calculations. Do not use `float` or `double`.

You shall use [std::cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal and you shall use [std::cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard.

The program reads in six values from the terminal, stores them in at least six different variables and then prints out a message summarizing the data and the resulting calculation.

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

The main goal of this exercise is for you to practice writing function definitions. The starter code has four functions that you need to complete.

### `JulianDay`

```C++
// Given a month, day, and year, calculate the Julian day number using the
// Fliegel & Van Flandern equation.
int JulianDay(int month, int day, int year)
```

### `DateDifference`

```C++
// Return the number of days between a start date and end date.
int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year)
```

### `PrintDate`

```C++
// Print the given date to standard output in the format MM/DD/YYYY
void PrintDate(int month, int day, int year)
```

### `main`

As usual, you need to complete the program's `main` function. This is the last of the four functions.

## Example Input and Output

The input and output of your program should match the following.

```
$ ls
date_difference.cc  Makefile  README.md
$ make all
set -e; clang++ -MM -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 date_difference.cc \
| sed 's/\(date_difference\)\.o[ :]*/\1.o date_difference.d : /g' > date_difference.d; \
[ -s date_difference.d ] || rm -f date_difference.d
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 -c date_difference.cc
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -o date_difference date_difference.o 
$ ./date_difference
Enter a start month: 1
Enter a start day: 1
Enter a start year: 2020

Enter an end month: 1
Enter an end day: 1
Enter an end year: 2021

The number of days between 1/1/2020 and 1/1/2021 is 366 days
$ ./date_difference
Enter a start month: 1
Enter a start day: 1
Enter a start year: 1990

Enter an end month: 1
Enter an end day: 1
Enter an end year: 2021

The number of days between 1/1/1990 and 1/1/2021 is 11323 days
$ 
```

## Test Cases

As usual, test your program against the test suite below.

| Test Case | Input                      | Expected Output                                                       |
|-----------|----------------------------|-----------------------------------------------------------------------|
| 1         | 1, 1, 2022, 1, 1, 2023     | `The number of days between 1/1/2022 and 1/1/2023 is 365 days`        |
| 2         | 1, 1, 1984, 1, 1, 1985     | `The number of days between 1/1/1984 and 1/1/1985 is 366 days`        |
| 3         | 12, 25, 1275, 12, 25, 2522 | `The number of days between 12/25/1275 and 12/25/2522 is 455457 days` |
| 4         | 9, 21, 2022, 10, 31, 1980  | `The number of days between 9/21/2022 and 10/31/1980 is -15300 days`  |
| 5         | 10, 1, 79, 9, 23, 2022     | `The number of days between 10/1/79 and 9/23/2022 is 709658 days`     |

## Next Steps

After you have pushed your code, you are done with this lab. You may ask your TA for permission to sign out and leave.
