/********************************************************************
 * The main file to interpret commands.
 * Tasks:
 * 1. Interpret each command from the command list.
 * 2. Execute each command
 *
 * This code makes usage of AbstractCommand and its derivated classes
 *********************************************************************/

#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "AbstractCmd.h"
#include "ExternalCmd.h"
#include "InternalCmd.h"

#define TRUE 1
#define FALSE 0

using namespace std;

//GLOBAL DEFINITIONS
extern AbstractCmd *ComList[10];
extern int NumCommands;

int read_cmd_file(string inFileName, vector<string>& cmdListPtr);
void readCom();

int main(int argc, char* argv[])
{ 

	readCom();


#ifdef LOG
	cout << "\nRead this code to find out how you can read the commands.\n"  << endl;

	cout << "NumCommands: " << NumCommands << endl;
	cout << "Command 0's type is " << ComList[0]->type << endl;
	ExternalCmd *FirstCommand = (ExternalCmd *) ComList[0];
	// Be sure to do the typecast otherwise the following lines would not work.
	// Incorrect typecast would lead to run time error.

	cout << "Command 0 has " << FirstCommand->numParameters << " parameters" << endl;
	cout << "Command 0's first parameter is " << FirstCommand->parameters[0] << endl;
	cout << "Command 0's second parameter is " << FirstCommand->parameters[1]  << endl;

	cout << endl;
	cout << endl;
	cout << "This is a quick way to see what the command is" << endl;

	ComList[0]->print();
	cout << endl;

	ComList[1]->print();
	cout << endl;

	ComList[2]->print();
	cout << endl;

	cout << endl;
	cout << endl;

	cout << "You could run them by implementing executeCmd function of each class.  But you do not have to follow this approach. You can implement it as you wish using stuff from class with fork/exec." << endl;
	cout << "If executeCmd is implemented correctly, the following would work:\n" << endl;
#endif

	char path[1000];

	for (int i = 0; i < NumCommands; ++i) {
		ComList[i]->print();
		ComList[i]->executeCmd();
		cout<<endl<<endl;
	}


}
