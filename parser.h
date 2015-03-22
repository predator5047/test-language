#include "lexer.h"

#ifndef PARSER_H
#define PARSER_H

class Parser {
private:
	Lexer lex;

public:
	Parser(const std::string &file);

	int AddExp();
	int MultExp();
	int Exp(); 
	int Eval();
};

#endif
