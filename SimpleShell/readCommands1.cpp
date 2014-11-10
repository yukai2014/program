/********************************************************************
 * Commands input
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
#include "InpRedirect.h"
#include "OutpRedirect.h"

#define TRUE 1
#define FALSE 0

using namespace std;

//GLOBAL DEFINITIONS
AbstractCmd *ComList[10];
int NumCommands;

int read_cmd_file(string inFileName, vector<string>& cmdListPtr);

void readCom()
{
	ExternalCmd * ExtCmd1, *ExtCmd2;
	InternalCmd *IntCmd1, *IntCmd2, *IntCmd3, *IntCmd4, *IntCmd5;

	ExtCmd1 = new ExternalCmd("ls -l");
	ExtCmd1->type = EXTERNALCMD;
	ExtCmd1->numParameters = 2;
	ExtCmd1->parameters[0] = "ls";
	ExtCmd1->parameters[1] = "-l";
	ComList[0] = ExtCmd1;


	IntCmd1 = new InternalCmd("cd new");
	IntCmd1->type = INTERNALCMD ;
	IntCmd1->numParameters = 2;
	IntCmd1->parameters[0] = "cd";
	IntCmd1->parameters[1] = "new";
//	IntCmd1->parameters[1] = "./";
	ComList[1] = IntCmd1;

	ExtCmd1 = new ExternalCmd("ls -l");
	ExtCmd1->type = EXTERNALCMD;
	ExtCmd1->numParameters = 2;
	ExtCmd1->parameters[0] = "ls";
	ExtCmd1->parameters[1] = "-1";
	ComList[2] = ExtCmd1;

	ExtCmd2 = new ExternalCmd("echo 123 345");
	ExtCmd2->type = EXTERNALCMD;
	ExtCmd2->numParameters = 3;
	ExtCmd2->parameters[0] = "echo";
	ExtCmd2->parameters[1] = "123";
	ExtCmd2->parameters[2] = "345";
	ComList[3] = ExtCmd2;

	NumCommands = 4;

	ExternalCmd *sortc;

	sortc = new ExternalCmd("sort -r");
	sortc->type = EXTERNALCMD;
	sortc->numParameters = 2;
	sortc->parameters[0] = "sort";
	sortc->parameters[1] = "-r";

	InpCmd *InpCmd1;
	InpCmd1 = new InpCmd((char*)"fruits.txt", sortc); // sort -r < fruits.txt
	InpCmd1->type = INPCMD;
	ComList[NumCommands++] = InpCmd1;

	OutpCmd *OutpCmd1;
	OutpCmd1 = new OutpCmd((char*)"fruits123.txt", ExtCmd1); // ls -l > fruits.txt
	OutpCmd1->type = OutPCMD;
	ComList[NumCommands++] = OutpCmd1;

	IntCmd2 = new InternalCmd("list");
	IntCmd2->type = INTERNALCMD ;
	IntCmd2->numParameters = 1;
	IntCmd2->parameters[0] = "list";
	ComList[NumCommands++] = IntCmd2;

	IntCmd3 = new InternalCmd("curpid");
	IntCmd3->type = INTERNALCMD ;
	IntCmd3->numParameters = 1;
	IntCmd3->parameters[0] = "curpid";
	ComList[NumCommands++] = IntCmd3;

	IntCmd4 = new InternalCmd("parpid");
	IntCmd4->type = INTERNALCMD ;
	IntCmd4->numParameters = 1;
	IntCmd4->parameters[0] = "parpid";
	ComList[NumCommands++] = IntCmd4;

	IntCmd5 = new InternalCmd("cd invalid");
	IntCmd5->type = INTERNALCMD ;
	IntCmd5->numParameters = 2;
	IntCmd5->parameters[0] = "lsl";
	IntCmd5->parameters[1] = "invalid";
	ComList[NumCommands++] = IntCmd5;
}
