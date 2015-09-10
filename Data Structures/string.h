#ifndef STRING_H
#define STRING_H

// string.h

#include <iostream>

using namespace std;

class String {
        int size;
        char * buffer;
public:
        String();
        String(const String& object);
        String(const char *p);
        ~String();
        String & operator=(const String& object);
        String & operator+=(const String& object);
        int length();
        char & operator[](const int index);

	// other methods

        friend bool operator==(const String& object, const String& object2);
        friend bool operator<=(const String& object, const String& object2);
        friend bool operator<(const String& object, const String& object2);
        friend ostream & operator<<(ostream& out, const String& object);
};

#endif
