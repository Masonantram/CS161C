#ifndef UNTITLED1_HEADER_HPP

const int HARD_ROW = 5, HARD_COL = 6, EASY_ROW = 4, EASY_COL = 4;
const char SPACE = ' ', UNKNOWN = 'X', MOVE = 'X';

inline int getIndex (int rowIndex, int colIndex, int colLength);
int getInteger (int min, int max);
void shuffle (char* board, int size);
void displayInstructions ();
void difficulty (int* mode, int* rowLength, int* colLength);
char* createBoard (int mode);

void showBoard (const char* board, int rowLength, int colLength);
void showBoard (const char* board, int rowLength, int colLength, const char* move, int row1, int col1);
void showBoard (const char* board, int rowLength, int colLength, const char* move, int row1, int col1, int row2, int col2);

void getMove (int rowLength,int colLength,const char* board, char* move, int& row1, int& col1);
void getMove (int rowLength,int colLength,const char* board, char* move, int row1, int col1, int& row2, int& col2);

bool checkMatch (const char* board, int colLength, int row1, int col1, int row2, int col2);
void updateBoard (char* board, int colLength, int row1, int col1, int row2, int col2, int& count);
void checkDone (const char* board, int rowLength, int colLength, bool& done, int count);
bool yesOrNo(std::string message);
void restart (char* move, bool& done, int& guesses,  int rowLength, int colLength, int& count);

#define UNTITLED1_HEADER_HPP

#endif //UNTITLED1_HEADER_HPP
