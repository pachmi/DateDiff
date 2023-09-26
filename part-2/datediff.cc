// Daniel Thibault
// daniel.thibault@csu.fullerton.edu
// @JustDanielThanks
// @pachmi

#include <iostream>

// Given a month, day, and year, calculate the Julian day number using the
// Fliegel & Van Flandern equation.
int JulianDay(int month, int day, int year) {
  // X: write statements to implement this function, and delete this comment
  int julian_day = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 +
                   367 * (month - 2 - (month - 14) / 12 * 12) / 12 -
                   3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
  // X: replace this return statement with one that actually works
  return julian_day;
}

// Return the number of days between a start date and end date.
int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {
  // X: write statements to implement this function, and delete this comment
  int difference{(JulianDay(end_month, end_day, end_year) -
                  JulianDay(start_month, start_day, start_year))};
  // X: replace this return statement with one that actually works
  return difference;
}

// Print the given date to standard output in the format MM/DD/YYYY
void PrintDate(int month, int day, int year) {
  // X: write statements to implement this function, and delete this comment
  std::cout << month << "/" << day << "/" << year;
}

// Prompt the computer with a question, capture their answer, and return it to
// the caller
int PromptForInt(std::string query) {
  // X: write statements to implement this function, and delete this comment
  // Hint: On Canvas, find the sample code named cpsc120_prompt.cc
  std::cout << query;
  int answer;
  std::cin >> answer;
  return answer;
  // X: replace this return statement with one that actually works
}

int main(int argc, char* argv[]) {
  // X: Declare and initalize an integer variable named start_month, using
  // the function PromptForInt. The prompt must be "Enter a start month: "
  int start_month{PromptForInt("Enter a start month: ")};
  // X: Declare and initalize an integer variable named start_day, using the
  // function PromptForInt. The prompt must be "Enter a start day: "
  int start_day{PromptForInt("Enter a start day: ")};
  // X: Declare and initalize an integer variable named start_year, using the
  // function PromptForInt. The prompt must be "Enter a start year: "
  int start_year{PromptForInt("Enter a start year: ")};
  // X: Declare and initalize an integer variable named end_month, using the
  // function PromptForInt. The prompt must be "Enter an end month: "
  int end_month{PromptForInt("Enter an end month: ")};
  // X: Declare and initalize an integer variable named end_day, using the
  // function PromptForInt. The prompt must be "Enter an end day: "
  int end_day{PromptForInt("Enter an end day: ")};
  // X: Declare and initalize an integer variable named end_year, using the
  // function PromptForInt. The prompt must be "Enter an end year: "
  int end_year{PromptForInt("Enter an end year: ")};
  // X: Declare an initalize an integer variable named difference, using the
  // function DateDifference.
  int difference{DateDifference(start_month, start_day, start_year, end_month,
                                end_day, end_year)};

  // X: Using std::cout, output the string "The number of days between"
  std::cout << "The number of days between ";
  // X: Call PrintDate to print the start date
  PrintDate(start_month, start_day, start_year);
  // X: Using std::cout, output the string " and "
  std::cout << " and ";
  // X: Call PrintDate to print the end date
  PrintDate(end_month, end_day, end_year);
  // X: Using std::cout, output the string " is "
  std::cout << " is ";
  // X: Using std::cout, output the value of the variable named difference
  // (which is the difference calculated between our start date and end date).
  std::cout << difference;
  // X: Using std::cout, output the string " days.\n"
  std::cout << " days.\n";

  return 0;
}
