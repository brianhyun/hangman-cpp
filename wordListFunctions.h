#ifndef WORDLISTFUNCTIONS_H
#define WORDLISTFUNCTIONS_H

using std::ifstream;
using std::string;

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

#endif




