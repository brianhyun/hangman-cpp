// fileio.cpp -- reading from a file
#include <iostream> 
#include <string>
#include <fstream>

// required for random number generator 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::ifstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

// Function Prototypes 
int numOfWordsInFile(string filename);

string* fillArrWithWordsFromFile(string* wordList, string filename);

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

// Function Definitions
int numOfWordsInFile(string fileName) {
	// Create an ifstream object to manage the input stream. 
	// The ifstream object is derived from the istream class (and thus the namespace);
	ifstream fin; 
	// Associate the object with a particular file. 
	// Open the specified file for reading. 
	fin.open(fileName);
	// These two lines can be combined into one statement as follows: ifstream inFile("word-list.txt");
	// This latter method is preferred according to a user on Stack Overflow. 
	
	if(fin.is_open()) {
		int lineCount = 0; 
		string line; // for getline() method; 

		// Get the number of lines (which corresponds to the number of words) within the file. 
		while(!fin.eof()) {
			getline(fin, line);
			lineCount++;
		}
		return lineCount; 
	} else {
		return -1;
	}
}

string* fillArrWithWordsFromFile(string* wordList, string filename){
	// Checks needn't be run since the first function handles the checks. 
	// If the program reaches this function, then it means that the file is accessible and able to be opened. 
	ifstream fin(filename);

	string line; 
	int index = 0; 

	while(!fin.eof()) {
		getline(fin, line); 
		wordList[index] = line;
		index++;
	}
	
	return wordList; 
}
