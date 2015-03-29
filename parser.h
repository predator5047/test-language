#include "lexer.h"
#include "ast.h"

#ifndef PARSER_H
#define PARSER_H

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
