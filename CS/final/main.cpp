#include "finalPractical_MWA.cpp"
#include <iostream>
using namespace std;

// This is a simple word guessing game.
//void getWord(std::string theWord);
//char getLetter();

int main() {
    string theWord, theGuess;
    char curGuessLetter, curWordLetter;
    cout << "This is a simple word guessing game. \n";
    cout << "It will read in a 5 letter word from a file \n";
    cout << "and ask you to guess it, one letter at a time. \n";

    // get a word to guess
    getWord(theWord);

    while (theWord != "done") {
        // initialize theGuess to have no matches, represented by underscore blanks
        theGuess = "_____";

        // loop through all words in the input file
        do {
            cout << "Word: " << theGuess << endl;

            // get a letter guess from the user
            curGuessLetter = getLetter();

            // check if guessed letter is in theWord and replace appropriate blanks
            for (int i = 0; i < theWord.length(); i++) {
                curWordLetter = theWord[i];
                if (curWordLetter == curGuessLetter) {
                    theGuess[i] = curGuessLetter;
                }
            }
        } while (theWord != theGuess);

        cout << "\n     Great job! You got the word *" << theGuess << "*.\n";

        // get next word from input file
        getWord(theWord);

        if (theWord != "done")
            cout << "     Let's try another word.\n\n";
    }

    cout << "\nThanks for playing!" << endl;
    return 0;
}

