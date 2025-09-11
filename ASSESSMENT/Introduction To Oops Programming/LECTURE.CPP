#include<iostream.h>
#include<conio.h>
#include<string.h>

// Class to represent a single Lecture
    class Lecture
{
    char lecturerName[50];
    char subjectName[50];
    char courseName[50];
    int numberOfLectures;

    public:
    // Constructor
    Lecture()
    {
	strcpy(lecturerName, "Not Assigned");
	strcpy(subjectName, "Not Assigned");
	strcpy(courseName, "Not Assigned");
	numberOfLectures = 0;
    }

    // Method to assign lecture details
    void addLectureDetails(char lName[], char sName[], char cName[], int lectures)
    {
	strcpy(lecturerName, lName);
	strcpy(subjectName, sName);
	strcpy(courseName, cName);
	numberOfLectures = lectures;
    }

    // Method to display lecture details
    void displayLectureDetails()
    {
	cout << "\n-----------------------------------";
	cout << "\nLecturer Name   : " << lecturerName;
	cout << "\nSubject Name    : " << subjectName;
	cout << "\nCourse Name     : " << courseName;
	cout << "\nNo. of Lectures : " << numberOfLectures;
	cout << "\n-----------------------------------";
    }
};

// Class to manage multiple lectures
    class LectureManagementSystem
{
    Lecture lectureList[5]; // Array for 5 lecturers

    public:
    // Method to add lecture details into system
    void addLecture(int index, char lName[], char sName[], char cName[], int lectures)
    {
	lectureList[index].addLectureDetails(lName, sName, cName, lectures);
	cout << "\n Lecture added successfully for " << lName << "\n";
    }

    // Method to display all lecture details
    void displayAllLectures()
    {
	cout << "\n\n All Lecture Details:\n";
	for (int i=0;i<5;i++)
	{
	    lectureList[i].displayLectureDetails();
	}
    }
};

// ------------------- Program -------------------
int main()
{
    clrscr();

    LectureManagementSystem system;

    char name[50], subject[50], course[50];
    int lectures;

    cout << "----- Lecture Management System -----\n";

    // Taking details for 5 lecturers
    for (int i = 0; i < 5; i++)
    {
	cout << "\nEnter details for Lecturer " << (i + 1) << ":\n";
	cout << "Enter Lecturer Name: ";
	cin >> name;
	cout << "Enter Subject Name: ";
	cin >> subject;
	cout << "Enter Course Name: ";
	cin >> course;
	cout << "Enter Number of Lectures: ";
	cin >> lectures;

	system.addLecture(i, name, subject, course, lectures);
    }

    // Display all lecture details
    system.displayAllLectures();

    getch();
    return 0;
}