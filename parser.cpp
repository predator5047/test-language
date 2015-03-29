#include "parser.h"
#include "token.h"
#include "ast.h"

Parser::Parser(const std::string& file) : lex(file) {

}

Expression* Parser::Term() {
	Expression *left = Factor(), *right;
	TokenId op_id = lex.PeekToken().Id;

	while (op_id == PLUS || op_id == MINUS) {
		lex.NextToken();
		right = Factor();

		BinaryOperator *temp = new BinaryOperator(left, right, op_id);
		left = temp;

		op_id = lex.PeekToken().Id;
	}

	return left;
}

Expression* Parser::Factor() {
	Expression *left = Primary(), *right;
	TokenId op_id = lex.PeekToken().Id;

	while (op_id == MULT || op_id == DIV) {
		lex.NextToken();
		right = Primary();

		BinaryOperator *temp = new BinaryOperator(left, right, op_id);
		left = temp;

		op_id = lex.PeekToken().Id;
	}

	return left;
}

Expression* Parser::Primary() {
	Expression *expr = NULL;

	if (lex.PeekToken().Id == NUMBER) {
		expr = new Constant(lex.NextToken());	
	} else if (lex.PeekToken().Id == MINUS) {
		lex.NextToken();
		expr = new UnaryOperator(Primary(), MINUS);
	} else if (lex.PeekToken().Id == LPAREN) {
		lex.NextToken();
		
		expr = Term();

		lex.NextToken();
	}
	
	return expr;
}
