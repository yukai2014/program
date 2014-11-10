/********************************
* External command implementation *
*********************************/
#include "ExternalCmd.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

//Destructor
ExternalCmd::~ExternalCmd()
{
	//cout << "ExternalCmd destructor called" << endl;
}

// Execute command method
void ExternalCmd::executeCmd()
{
	int i;

	// save parameters in char*[], and send it to execvp().
	char **argv = new char*[numParameters+1];
	for (i = 0; i < numParameters; ++i) {
		argv[i] = (char*)parameters[i].c_str();
	}
	argv[i] = 0;


	int pid = -1;
	if ((pid = fork()) == 0) {	// child process
		int ret = execvp(parameters[0].c_str(), argv);	//  The execvp() functions provide  an  array  of  pointers  to
																		//	null-terminated  strings  that represent the argument list available to
																		//	the new program.  The first argument, by convention,  should  point  to
																		// the  filename  associated  with  the file being executed.

		if (ret == -1) {	// if execvp fail, return -1, and set errno.
			perror("exec failed. The reason is:");		// output the error info
		}
	}
	else if (pid > 0){
		wait(NULL);	// wait till child process terminates, in another word, wait till an external command is executed
	}
	else {
		perror("error when fork");
	}
}

void ExternalCmd::print()
{

	cout << "This command has " << numParameters << " parameters" << endl;
	for (int j = 0 ; j < numParameters; j++)
	{
		cout << "Parameter " << j << " is \"" << parameters[j] << "\"  " ;
	}
	cout<<endl;
}
