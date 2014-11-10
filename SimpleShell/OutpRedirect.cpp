/********************************************
 * Output Redirection command implementation *
 *********************************************/
#include "OutpRedirect.h"
#include "ExternalCmd.h"

OutpCmd::OutpCmd(char *f, AbstractCmd *p1)
:AbstractCmd()
{
	command = p1;
	strncpy(fname, f,MAX_FNAME_CHAR);
}

void OutpCmd::print()
{
	cout << "This is a command with output redirection." << endl;
	cout << "The command is " << endl;
	command->print();
	cout << "The file name is " << fname << endl;
}

void OutpCmd::executeCmd()
{
	ExternalCmd * e = NULL;

	if (command->type == EXTERNALCMD) {	// transform command to ExternalCmd type
		e = (ExternalCmd *)command;
	}

	int i;
	char **argv = new char*[e->numParameters+1];
	for (i = 0; i < e->numParameters; ++i) {
		argv[i] = (char*)(e->parameters[i].c_str());
		//		cout<<argv[i]<<"--";
	}
	argv[i++] = (char*)NULL;

	int pid;
	int fd;

	if ((pid = fork()) == 0) {	// child process
		fd = open(fname, O_RDWR|O_CREAT, 0666);
		dup2(fd, STDOUT_FILENO);	// copy the file fd to stdout, then redirect output to this file

		int ret = execvp(e->parameters[0].c_str(), argv);
		if (ret == -1) {
			perror("exec failed. The reason is:");
		}
	}
	else {	// parent process
		waitpid(pid, NULL, 0);	// wait until the child process terminates
		close(fd);
	}
}
