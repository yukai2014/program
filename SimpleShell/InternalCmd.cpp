/**********************************
 * Internal command implementation *
 ***********************************/
#include "InternalCmd.h"
#include "InpRedirect.h"
#include "OutpRedirect.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

extern AbstractCmd *ComList[10];
extern int NumCommands;

using namespace std;
//Destructor
InternalCmd::~InternalCmd()
{
	//cout << "InternalCmd destructor called" << endl;
}

// Execute command method
void InternalCmd::executeCmd()
{
	int i;
	char **argv = new char*[numParameters+1];
	for (i = 0; i < numParameters; ++i) {
		argv[i] = (char*)parameters[i].c_str();
	}
	argv[i] = (char*)NULL;

	if (parameters[0] == "cd") {	// cd command should change the current working directory of the calling process
		chdir(parameters[1].c_str());		// set the process's working directory to filename.
	}
	else if (parameters[0] == "list") {
		for (i = 0; i < NumCommands; ++i) {
			if (ComList[i] == this) {
				break;
			}
			else {
//				ComList[i]->print();
				if (ComList[i]->type == INTERNALCMD || ComList[i]->type == EXTERNALCMD) {
					cout<<i<<": "<<ComList[i]->commandName<<endl;
				}
				else if (ComList[i]->type == INPCMD) {
					cout<<i<<": "<<((InpCmd*)ComList[i])->command->commandName<<endl;
				}
				else if (ComList[i]->type == OutPCMD) {
					cout<<i<<": "<<((OutpCmd*)ComList[i])->command->commandName<<endl;
				}
			}
		}
	}
	else if (parameters[0] == "curpid") {
		cout<<"The current process ID is: "<<getpid()<<endl;	// output the current process id
	}
	else if (parameters[0] == "parpid") {
		cout<<"The parent process ID is: "<<getppid()<<endl;	// output the parent process id
	}
	else {
		int ret = execvp(parameters[0].c_str(), argv);	// other command should call execvp()
		if (ret == -1) {
			perror("exec failed. The reason is:");	// if error appears, output the error info
		}
	}
}



void InternalCmd::print()
{

	cout << "This command has " << numParameters << " parameters" << endl;
	for (int j = 0 ; j < numParameters; j++)
	{
		cout << "Parameter " << j << " is \"" << parameters[j] << "\"  " ;
	}
	cout<<endl;
}

