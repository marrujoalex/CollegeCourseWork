#include <iostream>
#include <cassert>
#include "string.h"

using namespace std;

String::String() {
    buffer = NULL;
    size = 0;
}

String::String(const String& object) {
    size = object.size;
    buffer = new char[size];
    for (int i = 0; i < size; i++)
        buffer[i] = object.buffer[i];
}

String::String(const char* p) {
    int p_size = 0;
    for (const char *q=p; *q; q++)
        p_size++;
    buffer = new char[p_size];
    for (int i(0); i < p_size;i++)
        buffer[i] = p[i];
    size = p_size;
}

String::~String() {
    delete []buffer;
}

String & String::operator=(const String& object) {
    if (buffer != 0)
        delete[] buffer;
    size = object.size;
    buffer = new char[size];
    for (int i = 0; i < size; i++)
        buffer[i] = object.buffer[i];
    return *this;
}

String & String::operator+=(const String& object) {
    String temp = *this;
    for (int i = 0; i < object.size; i++)
        temp.buffer[i] += object.buffer[i];
    return temp;
}

int String::length() {
    return size;
}

char & String::operator[](const int index) {
    assert(index < size);
    return this->buffer[index];
}

bool operator==(const String& object, const String& object2) {
    if (object.size != object2.size)
        return false;
    else {        
        for (int i = 0; i < object2.size; i++) {
            if (object.buffer[i] != object2.buffer[i]) {
                return false;
            }
        }
    }
    return true;
}

bool operator<=(const String& object, const String& object2) {
    for (int i = 0; i < object2.size; i++) {
        if ((object.buffer[i] > object2.buffer[i]) && (object.buffer[i] != object2.buffer[i])) {
            return false;
        }
    }
    return true;
}

bool operator<(const String& object, const String& object2) {
    for (int i = 0; i < object2.size; i++) {
        if (object.buffer[i] > object2.buffer[i]) {
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& out, const String& object) {
    for (int i = 0; i < object.size; i++)
        out << object.buffer[i];
    return out;
}

