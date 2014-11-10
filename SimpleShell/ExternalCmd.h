/********************************
 * External command declarations *
 * !!DO NOT CHANGE THIS FILE!!	*
 *********************************/
#ifndef INCLUDE_EXTERNALCMD_H
#define INCLUDE_EXTERNALCMD_H

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include "AbstractCmd.h"

using namespace std;

class ExternalCmd : public AbstractCmd
{
private:

public:
	string parameters[MAXPARAM];
	int numParameters;

	// Constructor
	ExternalCmd(string x) : AbstractCmd(x) {}
	// Destructor
	~ExternalCmd();

	// Execute command method
	void executeCmd();

	virtual void print();

};
#endif
