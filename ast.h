#ifndef AST_H
#define AST_H

#include "lexer.h"

struct Node {
	virtual ~Node();
};

struct Expression {
	virtual ~Expression();
};

struct Variable : Expression {
	std::string Name;
};

struct BinaryOperator : Expression {
	Expression *Left, *Right;
	TokenId Op;

	BinaryOperator(Expression *left, Expression *right, TokenId op);
	~BinaryOperator();
};

struct UnaryOperator : Expression {
	Expression *Expr;
	TokenId Op;
	UnaryOperator(Expression *exp, TokenId op);
	~UnaryOperator();
};

struct Constant : Expression {
	Token Tok;	
	Constant(Token tok);
};

struct Assigment {
	Variable *Var;
	~Assigment();
};

#endif
