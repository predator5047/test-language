#ifndef TOKEN_H
#define TOKEN_H

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

#endif
