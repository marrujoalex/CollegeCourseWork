/********************************************************************************
 * Samuel Alex Marrujo
 * Lab2.cpp
 * 01/14/13
 * This program shows Time Complexity relating to the execution times of 
 * Selection sort, Insertion sort, and Bubble sort.
 ********************************************************************************/


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    vector<int> v;
    int n(0);
    while (n < 1000) {
        v.push_back((rand() % 999999));
        n++;
    }
    //selection sort
    for (int i = 0; i < n-1; i++) {
        
        for (int j = i+1; j < n; j++) {
             if (v[i] > v[j]) {
                swap(v[i], v[j]);
                
             }
             cout << v[i] << " " << v[j] << endl;
        }
    } 
/*
    //bubble sort
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j+1])
                swap(v[j], v[j+1]);
        }
    }

    //insertion sort
    for (int i = 1; i < n; i++) {
        for (int elem = v[i], j = i-1; j >=0 && elem < v[j]; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = elem;
    }
*/
    cin.ignore();
    cin.get();
    return 0;
}// main
