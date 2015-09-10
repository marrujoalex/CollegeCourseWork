#include <iostream>
#include <fstream>
#include <vector>
#include "employee.h"

using namespace std;

int main () {
    vector<Employee_Record> employees;
    int id;
    string department;
    string name;
    int salary;
    fstream io;
    io.open("records.txt", ios::in);
    cin >> id >> department >> name >> salary;
    while (!cin.eof()) {
   	    employees.push_back(Employee_Record(id, department, name, salary));
    	cin >> id >> department >> name >> salary;
    }
    for (int i = 0; i < employees.size(); i++) {
        for (j = i+1; j < employees.size()+1; j++) {
            if (employees.department[i] > employees.department[j]) {
                swap(employees.department[i], employees.department[j]);
                if (employees.salary[i] > employees.salary[j]) {
                    swap(employees.salary[i], employees.salary[j]);
                }
            }
        }
    }
    cin.ignore();
    cin.get();
    return 0;
}
