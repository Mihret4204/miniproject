// Firest cpp project for student management system
// This program allows you to add, view, search, and update student information.
// This is a simple console application that demonstrates basic object-oriented programming concepts in C++.
// It includes features like adding a student, displaying all students, searching by ID, and updating a student's grade.

#include<iostream>
#include<vector>
using namespace std;
class Student{
    private:
    int id;
    string name;
    float grade;
    public:
    Student(int s_id,string s_name,float s_grade){// Constructor to initialize student details(id, name, grade)
        id=s_id;
        name=s_name;
        grade=s_grade;
    }
    string getname () const{ return name; }// Getter 
    int getid()const{ return id; }
    float getgrade()const{ return grade; }
     void setgrade(float s_grade){
         grade=s_grade;
     }
     void printinfo() const {
        cout << "Student name: " << name << ", "
             << "Student id: " << id << ", "
             << "Student grade: " << grade << endl;
     }


};
class StudentManager{
    private:
     vector<Student> students;
     int id;
     string name;
     float grade;
    public:
    void addStudent(){
        cout << "Enter student's id: ";
        cin >> id;
        cin.ignore(); // Clear newline left in buffer
        cout << "Enter student's name: ";
        getline(cin, name);
        cout << "Enter student's grade: ";
        cin >> grade;
        students.push_back(Student(id, name, grade));
    }
    void displayAll(){
        for(const Student& s :students){
            s.printinfo();

        }
    }
    void searchById() {
        cout << "Enter ID to search: ";
        cin >> id;
        for (Student& s : students) {
            if (s.getid() == id) {
                s.printinfo();
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void updateGrade() {
        int id;
        float newGrade;
        cout << "Enter ID to update: ";
        cin >> id;

        for (Student& s : students) {
            if (s.getid() == id) {
                cout << "Enter new grade: ";
                cin >> newGrade;
                s.setgrade(newGrade);
                cout << "Grade updated.\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }
};
int main(){
        StudentManager StudentManagers;
        int choice;
        do{
                    cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Grade\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: StudentManagers.addStudent(); break;
            case 2: StudentManagers.displayAll(); break;
            case 3: StudentManagers.searchById(); break;
            case 4: StudentManagers.updateGrade(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice !=5);
    return 0;
}
