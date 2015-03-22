#ifndef AST_H
#define AST_H

#include "lexer.h"
#include <memory>

struct Expr {
	virtual ~Expr();
};

struct BinaryExp : Expr {
	std::unique_ptr<Expr> Left, Right;
	TokenId Op;
};

struct PrimaryExp : Expr {
	Token Tok;	
};


#endif
