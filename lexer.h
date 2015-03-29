#ifndef LEX_H
#define LEX_H

#include <fstream>
#include <cstdint>

enum TokenId {
	NUMBER, IDENT, EQ, PLUS, MINUS, DIV, MULT, SEMICOLON,
	UNKOWN, LPAREN, RPAREN
};

const int MAX_INDENT_LEN = 200;

struct Token {
	TokenId Id;
	union {
		double real_val;
		int32_t Value;
		char Name[MAX_INDENT_LEN + 1];
	};
};


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
