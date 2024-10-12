#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
std::string makeRectangle (char symbol, int length, int width);
    std::string makeSquare (char symbol, int side);
    std::string makeTriangle (char symbol, int height);
    std::string makeDiamond (char symbol, int width);

int main() {
    char shape, symbol;
    std::string line;
    int value1, value2;
    bool done = false;

  std::ifstream directions("infile.txt");

 directions >> shape >> symbol >> value1 >> value2;


 do {
      if (shape == 'r' || shape == 'R') {
std::cout << makeRectangle(1,1,1) << std::endl;
      }
      if (shape == 's' || shape == 'S') {
          std::cout << makeSquare(1,1) << std::endl;
      }
      if (shape == 't' || shape == 'T') {
          std::cout << makeTriangle(1,1) << std::endl;
      }
      if (shape == 'd' || shape == 'D') {
          std::cout << makeDiamond(1,1) << std::endl;
      }
      if (shape == 'e' || shape == 'E') {
          done = true;
      }
  }while(!directions.eof() || !done);

    return 0;
}

std::string makeRectangle (char symbol, int length, int width){
    return "rectangle";
}
std::string makeSquare (char symbol, int side){
    return "square";
}
std::string makeTriangle (char symbol, int height){
    return "triangle";
}
std::string makeDiamond (char symbol, int width){
    return "diamond";
}

/* makeRectangle (symbol, int length, int width)
 * stringstream symbol, length, width
 *
 * output rectangle using the right symbol and dimensions
 *
 *
 * makeSquare (symbol, int side)
 * stringstream symbol, side
 * output square using the right symbol and dimensions
 *
 * makeTriangle (symbol, int height)
 * stringstream symbol, height
 * output triangle using the right symbol and dimensions
 *
 * makeDiamond (symbol, int width)
 * stringstream symbol, width
 * output square using the right symbol and dimensions
 *
 * writeShape (string containing shape, reference parameter for output file)
 * writes shapeString to outfile
 * returns nothing
