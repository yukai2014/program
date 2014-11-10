/************************************************
 * Abstract base class for Command Interpreter	*
 * !!DO NOT CHANGE THIS FILE!!					*
 *************************************************/
#ifndef INCLUDE_ABSTRACTCMD_H
#define INCLUDE_ABSTRACTCMD_H
#define MAXPARAM 10
#define INTERNALCMD 0 
#define EXTERNALCMD 1
#define PIPECMD 2
#define INPCMD 3
#define OutPCMD 4

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class AbstractCmd
{	
public:
	/* Command Types */
	int type;
	string commandName;
	AbstractCmd();
	AbstractCmd(string x) {commandName = x;}
	virtual ~AbstractCmd() = 0;
	virtual void executeCmd() = 0;
	virtual void print() = 0;

};
#endif
