/********************************************************************************
 * Samuel Marrujo
 * Lab1.cpp
 * 01/07/13
 * This program converts infix to postfix expressions.
 * Status: 80%
 * Complexity Analysis: O(n^2)
 * - Considering O(n^2) since the while loop gives us n, and there are two while loops
 * inside the first while loop, giving 2n^2. Furthermore, there is an additional
 * while loop at the end of the algorithm, so we have 2n^2 + 2n + c, where c
 * is some constant. Since we discard constants in big oh notation, we are left
 * with O(n^2) for time complexity.
 ********************************************************************************/

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
#include<iostream>
#include<stack>

using namespace std;

// Function used to determine precedence between operators, where '*' and '/' are greater than '+' and '-'
int prec(char input) {
    
    if (input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input == ')') {
        if (input == '(') {
            return 2;
        }
        if (input == '*' || input == '/') {
            return 1;
        }
        if (input == '+' || input == '-') {
            return 0;
        }
    }
    else 
        return -2;
}

int main() {
    stack<char> value;
    char input('.');
    while (input != 'q') {
        cin >> input;
	    if ((input >= '0' && input <= '9') || (input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
		    cout << input << " ";
        }	
	    else 
            if (input == '(')   // '(' has lowest precedence in the stack, highest outside
		        value.push(input);
		    else if (input == ')') {
			    while (!(value.empty()) && value.top() != '(' ) {
			        cout << value.top() << " ";
				    value.pop();
                }
			    if (!(value.empty()))
				    value.pop();
			    else // no matching '('
			        cout << "ERROR! There exists a non-matching '('! \n";
            } 
		else if (value.empty() || prec(value.top()) < prec(input)) // bottom of stack has lower precedence than everything
			value.push(input);
		else if (prec(value.top()) >= prec(input)) {
			while (!(value.empty()) && prec(value.top()) >= prec(input)) {
				cout << value.top() << " ";
				value.pop();
            }	
			value.push(input);
        }
		else // check for errors
		    cout << "An error is possible. \n";
    }	
    while (!(value.empty())) {
	    cout << value.top() << " ";
	    value.pop();
    }    
    return 0;
}
