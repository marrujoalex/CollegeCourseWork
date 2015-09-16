#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

string convertInt(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
    }

int main() {
    float cp;
    float deg;
    cout << "Number of control points: ";
    cin  >> cp;
    cout << "Degree of spline: ";
    cin  >> deg;
    vector<float> knot;
    float kCount = cp + deg;
    knot.push_back(0);
    for (int i = 0; i < kCount; i++) {
        knot.push_back( (i + 1)/(kCount + 1) );
    }
    knot.push_back(1);
    for (int i = 0; i < knot.size(); i++) {
        int count = ( i + 1 );
        string strng = convertInt( count );
        if (count < 10)
                strng = ' ' + strng;
        cout << "Knot " << strng << ": " << knot[i] << endl;
    }
}