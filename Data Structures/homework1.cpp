/********************************************************************************
 * Samuel Marrujo
 * homework1.cpp
 * 01/21/13
 * This program demonstrates a program for variance. EXPAND THIS
 ********************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

//Function for variance, given in Problem #8, Pg21 in Textbook
float variance(float value, float avg, int& n) {
    for (int i = 0; i < n; i++) {
        (pow((value - avg),2))/n-1;
    }
    return value;
}

//Function to compute the average of all the numbers in the array
// RECHECK THIS FUNCTION!
float Average(float value2, int& n) {
    float average, sum(0);
    int i(0);
    for (; i < n; i++) {
        sum += value2;
    }
    average = sum/i;
    return average;
}

int main() {
    float d[100];
    float num, average(num);
    cin >> num;
    //if (num <= 0 && num >= 
    int n(0), i(0);
    d[i] = num;
    while (!cin.eof()) {
        n++;
        //Content for data here
        if (n > 1) {
            d[i] = variance(num, average, n);
            average = Average(d[i], n);
            cout << d[i] << endl;
            i++;
        }
        cin >> num;
    }
    cin.ignore();
    cin.get();
    return 0;
}// main
