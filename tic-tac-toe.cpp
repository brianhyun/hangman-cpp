// fileio.cpp -- reading from a file
#include <iostream> 
#include <string>
#include <fstream>
#include "wordListFunctions.h"

// required for random number generator 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::ifstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	// Hold filename in string variable. 
	string wordFile = "word-list.txt";

	// Extract number of words in specified file. 
	int wordCount = numOfWordsInFile(wordFile);

	// Declare an array with a size of the word list. 
	string wordList[wordCount];

	// Fill array with words from the word list. 
	fillArrWithWordsFromFile(wordList, wordFile);

	// initialize random seed 
	srand(time(NULL));

	// generate secret number between 1 and 10
	int randomNumber = rand() % (wordCount - 1);

	// store hangman word 
	string secretWord = wordList[randomNumber];
	string guessString = "";

	// for testing purposes
	// secretWord = "luck";

	// show hangman prompt 
	cout << "Hangman Word: ";
	for (int i = 0; i < secretWord.length(); i++) {
		guessString += "#";
	}
	cout << guessString << endl;

	// Prompt User
	int guesses = 10; 

	while (guesses > 0) {
		if (guesses == 6) {
			cout << "Enter guess: ";
		} else {
			cout << "Enter another guess: "; 
		}

		// show user what they guessed
		char letter; 
		cin >> letter; 

		int letterCount = 0;  

		// see if letter exists in the word
		for (int i = 0; i < secretWord.length(); i++) {
			if (secretWord[i] == letter) {
				guessString[i] = letter;
				letterCount++;
			}
		}

		if (letterCount > 0) {
			cout << "Good job!" << " The letter " << letter << " occurrences: " << letterCount << endl;
		} else {
			cout << "Sorry! That letter doesn't exist in this word!" << endl;
		}


		cout << "---------------------------------------------------" << endl;
		cout << "Hangman Word: " << guessString << endl;

		if (guessString.find("#") == -1) {
			break;
		}

		guesses--;
	}

	cout << "The word was " << secretWord << "." << endl;
	cout << "Better luck next time!" << endl;

	// successful completion
	return 0; 
}