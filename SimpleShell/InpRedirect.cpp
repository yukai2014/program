/*******************************************
 * Input Redirection command implementation *
 ********************************************/
#include "InpRedirect.h"
#include "ExternalCmd.h"


InpCmd::InpCmd(char *f, AbstractCmd *p1)
:AbstractCmd()
{
	command = p1;
	strncpy(fname, f,MAX_FNAME_CHAR);
}

void InpCmd::print()
{
	cout << "This is a command with input redirection." << endl;
	cout << "The command is " << endl;
	command->print();
	cout << "The file name is " << fname << endl;
}

void InpCmd::executeCmd()
{
	ExternalCmd * e = NULL;

		if (command->type == EXTERNALCMD) {
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
		char c;
		int fd;
		if ((pid = fork()) == 0) {	// child process
			fd = open(fname, O_RDWR|O_CREAT, 0666);	// open a file, with access of write and read and creating if not exist, whose mode is 666
			if (fd == -1) {
				perror("open file failed.");
			}
			dup2(fd, STDIN_FILENO);	// copy the file fd to stdin, then redirect input to this file
			close(fd);

			//		cout<<"in child 2"<<endl;
			int ret = execvp(e->parameters[0].c_str(), argv);
			if (ret == -1) {
				perror("exec failed. The reason is:");
			}
		}
		else {
			waitpid(pid, NULL, 0);	// waiting the child process
			close(fd);
		}
}
