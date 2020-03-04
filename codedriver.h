#ifndef codedriver_h
#define codedriver_h

#include <string>

static int gettoken();
enum Token {
	tok_eof = -1,

	// commands
	tok_def = -2,
	tok_extern = -3,

	// primary
	tok_identifier = -4,
	tok_number = -5
};
static std::string IdentifierStr;
static double NumVal;

static int CurTok;
static int getNextToken();

void Mainloop();
 
#endif