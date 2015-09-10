#ifndef "EMPLOYEE.H"
#define "EMPLOYEE.H"

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

#endif
