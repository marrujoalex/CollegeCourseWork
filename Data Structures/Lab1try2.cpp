// An algorithm for infix to postfix expression conversion.
// For example,   a + b - c     translates to   a b + c -
//                a + b * c     translates to   a b c * +
//                (a + 2) / (5 + d)   goes to   a 2 + 5 d + /
// Valid operands are single digits and characters: 0-9, a-z, A-Z
// Valid operators are: +, -, *, /, (, )
// Highest precedence:   * /
// Lowest precedence:    + -
// ) never goes on stack.
// ( has lowest precedence on the stack and highest precedence outside of stack.
// Bottom of the stack has the lowest precedence than any operator.
// Use a prec() function to compare the precedence of the operators based on the above rules.
// Note there is little error checking in the algorithm!

#include <iostream>
#include <stack>
using namespace std;

int main() {
while there is more input
	if input is an operand
		print input
	else
		if input is '('  // '(' has lowest precedence in the stack, highest outside
			push input on stack
		else if input is ')'
			while stack is not empty and top of stack is not '('
				print top of stack
				pop stack
			if stack is not empty
				pop stack
			else error  // no matching '('
		else if stack is empty or prec(top of stack) < prec(input) // bottom of stack has lower precedence than everything
			push input on stack
		else if prec(top of stack) >= prec(input)
			while stack is not empty and prec(top of stack) >= prec(input)
				print top of stack
				pop stack
			push input on stack
		else check for errors
while stack is not empty
	print top of stack
	pop stack
cin.ignore();
cin.get();
return 0;
}
