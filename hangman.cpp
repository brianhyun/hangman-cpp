// hangman.cpp - simple hangman game
#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h> 	// required for random number generator 
#include <stdlib.h> // required for random number generator 
#include <time.h>	// required for random number generator 
#include "wordListFunctions.h"

int main() {
	// namespace declarations
	using std::ifstream;
	using std::vector; 
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;

	string wordFile = "word-list.txt";

	int wordCount = numOfWords(wordFile);

	string wordList[wordCount];

	fillArr(wordList, wordFile);

	// initialize random seed 
	srand(time(NULL));
	// generate secret number between 1 and 10
	int randomNumber = rand() % (wordCount - 1);
 
	string secretWord = wordList[randomNumber];

	// Create a string that'll guide the user on their guesses. 
	string guessString = "";

	// Show hangman prompt 
	cout << "Hangman Word: ";
	for (int i = 0; i < secretWord.length(); i++) {
		guessString += "#";
	}
	cout << guessString << endl;

	int guesses = 10; 
	int guessIteration = 1;
	vector<char> guessedLetters(guesses);
	bool gotWord = false;

	while (guesses > 0) {
		// Prompt user
		cout << "Enter guess: ";

		// Store user's guess in guessLetters vector
		char letter; 
		cin >> letter; 
		guessedLetters.push_back(letter);

		int letterCount = 0;  

		// See if letter exists in the word
		for (int i = (guesses - 1); i < (guesses - 1) - guessIteration; i++) {
			// If so then, reveal the location of the letter within the word and 
			if (letter == secretWord[i]) {
				guessString[i] = letter;
				letterCount++;
			}
		}

		if (letterCount > 0) {
			cout << "Correct Guess!" << endl;
		} else {
			cout << "Unlucky!" << endl;
		}

		cout << "---------------------------------------------------" << endl;
		cout << "Hangman Word: " << guessString << endl;
	
		// Show letters the user has already guessed.
		cout << "Letters guessed: "; 
		for (int i = 0; i < guessIteration; i++) {
			cout << guessedLetters[i] << " ";
		}

		// If the user guessed the string, then break out of loop. 
		if (guessString.find("#") == -1) {
			gotWord = true;
			break;
		}

		// User used a guess so reduce guesses count by one. 
		guesses--;
		guessIteration++;
	}

	// Endgame Prompts
	if (gotWord == true) {
		cout << "##################################" << endl;
		cout << "Congratulations! You got the word!" << endl;
		cout << "##################################" << endl;
	} else {
		cout << "##################################" << endl;
		cout << "The word was " << secretWord << "." << endl;
		cout << "Better luck next time!" << endl;
		cout << "##################################" << endl;
	}

	// Program successful completion
	return 0; 
}