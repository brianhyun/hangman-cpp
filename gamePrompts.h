#ifndef GAMEPROMPTS_H
#define GAMEPROMPTS_H

using std::cout; 
using std::endl;
using std::string;

void endGamePrompt(bool gotWord, string secretWord) {
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
}

#endif