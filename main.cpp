#include <iostream>
#include "lexer.h"
using namespace std;

const string tokid_to_str[] = {
	"NUMBER", "IDENT", "EQ", "PLUS", "MINUS", "DIV",
	"MULT", "SEMICOLON", "UNKOWN"
};

int main() {
	Lexer l("test.txt");

	Token t = l.NextToken();

	while (t.Id != UNKOWN) {
		if (t.Id == IDENT) {
			cout << t.Name << " ";
		} else if (t.Id == NUMBER) {
			cout << t.Value << " ";
		} else {
			cout << tokid_to_str[t.Id] << " ";
		}
		t = l.NextToken();
	}
	
	cout << "\n";

	return 0;
}
