#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Employee_Record {
    int id;
    string department;
    string name;
    int salary;
public:
    Employee_Record(): id(0), department(""), name(""), salary(0) { }
    Employee_Record(int new_id, string new_department, string new_name, int new_salary): id(new_id), department(new_department), name(new_name), salary(new_salary) { }
    int get_id() { return id; }
    string get_department() { return department; }
    string get_name() { return name; }
    int get_salary() { return salary; }
    void set_department(string new_department) { department = new_department; }
    void set_name(string new_name) { name = new_name; }
    void set_salary(int new_salary) { salary = new_salary; }
};

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
        for (int j = i+1; j < employees.size()+1; j++) {
            if (department[i] > department[j]) {
                swap(department[i], department[j]);
                if (salary[i] > salary[j]) {
                    swap(salary[i], salary[j]);
                }
            }
        }
    }
    cin.ignore();
    cin.get();
    return 0;
}
