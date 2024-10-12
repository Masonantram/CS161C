#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string makeRectangle (char symbol, int length, int width);
std::string makeSquare (char symbol, int length);
std::string makeTriangle (char symbol, int length);
std::string makeDiamond (char symbol, int length);

    int main() {
        std::string line{};
        std::stringstream reader;
        bool done = false;
        char shape, symbol;
        int length, width;

        std::ifstream directions("infile.txt");

        if (!directions.good())
        {
            std::cout << "error" << std::endl;
        }

        if (directions.good())
        {
            std::cout << "yay" << std::endl;
        }

        do {
            while (getline(directions, line) || !directions.eof())
            {
                reader.clear();

                reader << line;

                if (line[0] == 'r' || line[0] == 'R')
                {
                    reader >> shape >> symbol >> length >> width;

                } else {
                    reader >> shape >> symbol >> length;
                }

                if (line[0] == 'r' || line[0] == 'R')
                {
                    std::cout << makeRectangle(symbol, length, width) << std::endl;
                }

                if (line[0] == 's' || line[0] == 'S')
                {
                    std::cout << makeSquare(symbol, length) << std::endl;
                }

                if (line[0] == 't' || line[0] == 'T')
                {
                    std::cout << makeTriangle(symbol, length) << std::endl;
                }

                if (line[0] == 'd' || line[0] == 'D')
                {
                    std::cout << makeDiamond(symbol, length) << std::endl;
                }

                if (line[0] == 'e' || line[0] == 'E')
                {
                    done = true;
                }

            }
        } while (!done);

        directions.close();
        return 0;
    }
