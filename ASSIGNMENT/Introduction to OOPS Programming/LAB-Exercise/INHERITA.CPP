#include <iostream>
#include <string>

class Person {
protected:
    string name;
    int age;

public:

    Person(string n, int a) : name(n), age(a) {}

    void displayInfo() {
        cout << "Name: " << name;
        cout << "Age : " << age;
    }
};

class Student : public Person {
private:
    string course;
    int rollNo;

public:
    Student(string n, int a, string c, int r) : Person(n, a), course(c), rollNo(r) {}

    void displayStudent() {
        cout << "\n--- Student Details ---";
        displayInfo(); 
        cout << "Course : " << course;
        cout << "Roll No: " << rollNo;
    }
};

class Teacher : public Person {
private:
    string subject;
    double salary;

public:
    // Constructor using base class constructor
    Teacher(string n, int a, string s, double sal) : Person(n, a), subject(s), salary(sal) {}

    // Display teacher info
    void displayTeacher() {
        cout << "\n--- Teacher Details ---";
        displayInfo();
        cout << "Subject: " << subject;
        cout << "Salary : " << salary;
    }
};

// Main function
void main() {

    clrscr();
    // Creating Student object
    Student s1("Rahul Sharma", 20, "Computer Science", 101);
    s1.displayStudent();

    // Creating Teacher object
    Teacher t1("Dr. Meena Patel", 45, "Mathematics", 55000);
    t1.displayTeacher();

    getch();
}
