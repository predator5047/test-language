#include "lexer.h"

#ifndef PARSER_H
#define PARSER_H

struct Expression;

class Parser {
private:
	Lexer lex;

public:
	Parser(const std::string &file);

	Expression* Term();
	Expression* Factor();
	Expression* Primary(); 
};

#endif
