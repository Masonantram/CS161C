// Fix the run time errors, so this code runs correctly.
// There are NO errors in the getFloat function definition.
// There is NO need to change any variable names or to add any new ones.

#include <iostream>
#include <regex>
#include <string>
using namespace std;

// calculate area
float calcArea(float l, float w) {
  float area = l * w;
  return area;
}

// get a number from the user (may contain a decimal portion) -- NO errors
float getFloat(string msg) {
  float value;
  string input;
  bool badInput = true;
  regex pattern("^[-+]?[0-9]*\.?[0-9]+$"); // matches a float

  do {
    cout << msg;

    // Read the input as a string to handle non-numeric input
    getline(cin, input);

    // Check if the input is a float
    if (regex_match(input, pattern)) {
      value = stof(input);
      badInput = false;
    } else {
      cout << "Invalid input. " << msg;
    }
  } while (badInput);
  return value;
}

int main() {
  float length, width, area ;

  length = getFloat("Please enter a length: ");
  width = getFloat("Please enter a width: ");
  area = calcArea(length, width);
  cout << "The area for length=" << length;
  cout << " and width=" << width << " is " << area << "." << endl;

  return 0;
}
