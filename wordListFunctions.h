#ifndef WORDLISTFUNCTIONS_H
#define WORDLISTFUNCTIONS_H

using std::ifstream;
using std::string;

// Take in a file with a list of words (each word on a separate line) and
// return the number of words in the file. 
int numOfWords(string fileName) {
	// Create an ifstream object to manage the input stream. 
	ifstream fin; 
	// Associate the object with a particular file and open the specified file for reading. 
	fin.open(fileName);
	// Can be combined into one statement as follows: ifstream inFile(filename);
	
	if(fin.is_open()) {
		int lineCount = 0; 
		// for getline() method; 
		string line; 

		while(!fin.eof()) {
			getline(fin, line);
			lineCount++;
		}
		return lineCount; 
	} else {
		return -1;
	}
}

// Take in an array and a file with a list of words and fill array with words.
string* fillArr(string* wordList, string filename){
	// Checks needn't be run since the first function handles the checks. 
	// If the program reaches this function, then it means that the file 
	// is accessible and able to be opened. 
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




