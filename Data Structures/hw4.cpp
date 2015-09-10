/********************************************************************************
 * Samuel Marrujo
 * hw4.cpp
 * 03/01/13
 *
 * Description: This program constructs a Course Registration System. There 
 *              contains 5 courses. Choose a limit of 3 or 4 for each course. 
 *              The student file contains the requests of about 10 students. 
 * 
 * Note: There would be more than 10 records in this file as a student usually 
 *       requests more than one course. 
 *
 ********************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>

using namespace std;

class Course;
class Student;

class Student {
    typedef list<Course *>::iterator citerator;
    
public:
    Student(string n): nameText(n) {}
    ~Student();
    
    string name() {return nameText;}
    void addCourse(Course * c) {courses.push_back(c);}
    citerator firstCourse() {return courses.begin();}
    citerator lastCourse() {return courses.end();}
    void removeCourse(citerator & citr) {courses.erase(citr);}

protected:
    string nameText;
    list<Course *> courses;

};//Class Student

class Course {
public:
    Course(string n, int s): name(n), max(s) {}
    ~Course();
    
    bool full() {return students.size() >= max;}
    void addStudent(Student * s) {students.push_back(s);}
    void generateClassList();
    string getCourseName() {return name;}
    
protected:
    string name;
    int max;
    list<Student *> students;
    
};//class Course      

list <Student *> all_students; // Global Variable for Students
list <Course *> all_courses; // Global Variable for Courses

//Function used to compare student names by string
bool studentCompare (Student * a, Student * b) {
    return a->name() < b->name();
}//studentCompare

//Find (or make) a student record for the given name
Student * findStudent(string & searchName) {
    list <Student *>::iterator start, stop;
    start = all_students.begin();
    stop = all_students.end();
    for ( ; start != stop; ++start) 
        if ((*start)->name() == searchName)
            return *start;
    Student * newStudent = new Student(searchName);
    all_students.push_back(newStudent);
    return newStudent;        
}//findStudent

//Find (or make) a course record for the given name
Course * findCourse(string & searchName, int & size) {
    list <Course *>::iterator start, stop;
    start = all_courses.begin();
    stop = all_courses.end();
    for ( ; start != stop; ++start) 
        if ((*start)->getCourseName() == searchName)
            return *start;
    Course * newCourse = new Course(searchName, size);
    all_courses.push_back(newCourse);
    return newCourse;        
}//findCourse

//Fill as many students as possible in each course
//Priority given by input order (first come, first served)
void fillCourses() {
    list<Student *>::iterator s_start, s_end;
    s_start = all_students.begin();
    s_end = all_students.end();
    
    for ( ; s_start != s_end; ++s_start) {
        list<Course *>::iterator c_start, c_end, c_next;
        c_start = (*s_start)->firstCourse();
        c_end = (*s_start)->lastCourse();
        for ( ; c_start != c_end; c_start = c_next) {
            c_next = c_start; 
            ++c_next;
            if (!(*c_start)->full())
                (*c_start)->addStudent(*s_start);
            else
                (*s_start)->removeCourse(c_start);
        }
    }
}//fillCourses

//Prints the class list of all the students
void Course::generateClassList() {
     
    students.sort(studentCompare);
    cout << "Class list for " << name << endl;
    list<Student *>::iterator start, stop;
    start = students.begin();
    stop = students.end();
    for ( ; start != stop; ++start)
        cout << (*start)->name() << endl;    
}// Course -> generateClassList

//Read the list of courses from the given input stream
void readCourses (ifstream & infile) {
    string name;
    int max;
    while (infile >> name >> max) {
        Course * newCourse = new Course(name, max);
        all_courses.push_back(newCourse);
    } 
}// Read Courses

//Read the list of student records from the given input stream
void readStudents (ifstream & infile) {
    string name;
    string course;
    int size(4); //Using size to just pass into the function. No comparison used here.
    while (infile >> name >> course) {
        Student * theStudent = findStudent(name);
        Course * theCourse = findCourse(course, size);
        if (theCourse != 0)
            theStudent->addCourse(theCourse);
        else
            cout << "Student " << name << " requested invalid course " << course << endl;
    }
}// Read Students

//Generate Class Lists for each Course
void generateCourseReports() {
    list<Course *>::iterator start, stop;
    start = all_courses.begin();
    stop = all_courses.end();
    for ( ; start != stop; ++start)
        (*start)->generateClassList();
}//generateCourseReports

//Generate class lists for students
void generateStudentReports() {
    list<Student *>::iterator s_start, s_stop;
    list<Course *>::iterator c_start, c_stop;
    s_start = all_students.begin();
    s_stop = all_students.end();
    
    for ( ; s_start != s_stop; ++s_start) {
        cout << "Class list for " << (*s_start)->name() << endl;
        c_start = (*s_start)->firstCourse();
        c_stop = (*s_start)->lastCourse();
        for ( ; c_start != c_stop; ++c_start)
            cout << (*c_start)->getCourseName() << endl;
    }    
}//generateStudentReports

// Function used to read in the input from the two files, and output
// the reports.
void readFiles() {
    ifstream file_one, file_two;
    file_one.open("input_file01.txt");
    readCourses(file_one);
    file_two.open("input_file02.txt");
    readStudents(file_two);
    fillCourses();
    generateCourseReports();
    generateStudentReports();
    file_one.close();
    file_two.close();
}//readFiles

int main() {
    readFiles();
    return 0;
}//main
