#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string &file_name) : fin(file_name) {

}

int Lexer::GetNoSp() {
	int c = fin.get();

	while (std::isspace(c)) {
	       	c = fin.get();
	}

	return c;
}

Token Lexer::NextToken() {
	int c = GetNoSp();
	Token tok;

	if (std::isalpha(c)) {
		int len = 0;
		tok.Id = IDENT;

		while (isalnum(c) && len < MAX_INDENT_LEN) {
			tok.Name[len++] = c;
			c = fin.get();
		}

		tok.Name[len] = '\0';
		fin.unget();
		return tok;
	}

	if (std::isdigit(c)) {
		int32_t num = 0;
		tok.Id = NUMBER;
		
		while (isdigit(c)) {
			num = num * 10 + c - '0';
			c = fin.get();
		}

		tok.Value = num;
		fin.unget();

		return tok;
	}
	
	switch (c) {
	case ';':
		tok.Id = SEMICOLON;
		break;
	case '=':
		tok.Id = EQ;
		break;
	case '+':
		tok.Id = PLUS;
		break;
	case '-':
		tok.Id = MINUS;
		break;
	case '*':
		tok.Id = MULT;
		break;
	case '/':
		tok.Id = DIV;
		break;
	default:
		tok.Id = UNKOWN;
	}

	return tok;
}


Token Lexer::Peek() {
	std::streampos pos = fin.tellg();
	Token tok = NextToken();

	fin.seekg(pos);

	return tok;
}
