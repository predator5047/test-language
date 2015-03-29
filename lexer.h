#ifndef LEX_H
#define LEX_H

#include <fstream>
#include "token.h"


class Lexer {
private:
	std::fstream fin;

public:
	Lexer(const std::string &file_name);

	int GetNoSp();

	Token PeekToken();

	Token NextToken();
};

#endif
