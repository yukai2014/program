/********************************
 * Internal command declarations *
 * !!DO NOT CHANGE THIS FILE!!	*
 *********************************/
#ifndef INCLUDE_INTERNALCMD_H
#define INCLUDE_INTERNALCMD_H

#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <time.h>
#include <iostream>
#include "AbstractCmd.h"

using namespace std;

class InternalCmd : public AbstractCmd
{
private:

public:
	string parameters[MAXPARAM];
	int numParameters;

	// Constructor
	InternalCmd(string x) : AbstractCmd(x) {}
	// Destructor
	~InternalCmd();

	// Execute command method
	void executeCmd();

	void print();

};
#endif
