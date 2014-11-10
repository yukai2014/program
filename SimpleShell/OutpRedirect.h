/******************************************
* Output redirection command declarations *
* !!DO NOT MODIFY NOR RENAME THIS FILE!!  *
*******************************************/
#ifndef INCLUDE_OUTPRD_H
#define INCLUDE_OUTPRD_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "AbstractCmd.h"

#define MAX_FNAME_CHAR 100
using namespace std;

class OutpCmd : public AbstractCmd
{
  private:
	void _set_instanceof() {}

  public:
    char fname[MAX_FNAME_CHAR]; // File name from where input is to be read. 
    AbstractCmd *command; // Abstract command pointer

	// Constructor
	OutpCmd(char *, AbstractCmd *);
	
	// Destructor
	~OutpCmd() {}
	
	// Execute command method
	void executeCmd();
	
    void print();
	
};
#endif
