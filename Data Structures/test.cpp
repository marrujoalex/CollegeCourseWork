#include <iostream>

#include "string.h"

using namespace std;

int main()
{
	String s1("abcd"), s2("abe");

	if ( not (s1 == s2) )
		if (s1 <= s2)
			cout << s1 << " <= " << s2 << endl;
		else
			cout << s1 << " > " << s2 << endl;
	else
		cout << "equal: " << s1 << " " << s2;
}
