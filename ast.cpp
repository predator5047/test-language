#include "ast.h"

Node::~Node() {

}

Expression::~Expression() {

}

BinaryOperator::~BinaryOperator() {
	if (Left) {
		delete Left;
	}
	if (Right) {
		delete Right;
	}
}

BinaryOperator::BinaryOperator(Expression *left, Expression *right, 
		TokenId op) :
	Left(left), Right(right), Op(op) {

}


UnaryOperator::UnaryOperator(Expression *expr, TokenId op) 
	: Expr(expr), Op(op) {

}

UnaryOperator::~UnaryOperator() {
	if (Expr) {
		delete Expr;
	}
}

Constant::Constant(Token tok) : Tok(tok) {

}

Assigment::~Assigment() {
	if (Var) {
		delete Var;
	}
}
