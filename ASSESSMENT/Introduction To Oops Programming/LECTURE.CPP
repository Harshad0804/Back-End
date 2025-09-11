#include <iostream>
#include <string>

class Lecture {
private:
    string lecturerName;
    string subjectName;
    string courseName;
    int numberOfLectures;

public:
    Lecture() {
        lecturerName = "Not Assigned";
        subjectName = "Not Assigned";
        courseName = "Not Assigned";
        numberOfLectures = 0;
    }

    Lecture(string name, string subject, string course, int lectures) {
        lecturerName = name;
        subjectName = subject;
        courseName = course;
        numberOfLectures = lectures;
    }

    void addLectureDetails(string name, string subject, string course, int lectures) {
        lecturerName = name;
        subjectName = subject;
        courseName = course;
        numberOfLectures = lectures;
    }

    void displayLectureDetails() {
        cout << "\n------------------------------------------";
        cout << "\n Lecturer Name     : " << lecturerName;
        cout << "\n Subject Name      : " << subjectName;
        cout << "\n Course Name       : " << courseName;
        cout << "\n Number of Lectures: " << numberOfLectures;
        cout << "\n------------------------------------------\n";
    }
};
void main() {

    clrscr();
    Lecture lectures[5];

    cout << "==============================\n";
    cout << "  Lecture Management System\n";
    cout << "==============================\n";

    for (int i = 0; i < 5; i++) {
        string name, subject, course;
        int noOfLectures;

        cout << "\nEnter details for Lecturer " << (i + 1) << ":\n";
        cout << " Enter Lecturer Name: ";
        getline(cin, name);
        cout << " Enter Subject Name: ";
        getline(cin, subject);
        cout << " Enter Course Name: ";
        getline(cin, course);
        cout << " Enter Number of Lectures: ";
        cin >> noOfLectures;
        cin.ignore(); // To avoid skipping next input due to newline

        lectures[i].addLectureDetails(name, subject, course, noOfLectures);
    }

    cout << "\n\n========= Displaying Lecturer Details =========\n";
    for (int i = 0; i < 5; i++) {
        lectures[i].displayLectureDetails();
    }

    cout << "\nThank you for using Lecture Management System!\n";

    getch();
}
