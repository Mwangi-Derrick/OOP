#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string regNo;
        string name;
        int marks;
        string grade;
    
    public:
        // Default constructor
        Student(){
            regNo = "";
            name = "";
            marks = 0;
            grade = "";
        }
        
        // Parameterized constructor
        Student(string reg, string n, int m){
            regNo = reg;
            name = n;
            marks = m;
            calculateGrade(); // Calculate grade when creating student
        }
        
        void calculateGrade(){
            if(marks >= 80){
                grade = "A";
            }
            else if(marks >= 70){
                grade = "B";
            }
            else if(marks >= 60){
                grade = "C";
            }
            else if(marks >= 50){
                grade = "D";
            }
            else{
                grade = "F";
            }
        }
        
        void displayStudentDetails(){
            cout << "\nStudent Details:" << endl;
            cout << "Registration Number: " << regNo << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
            cout << "Grade: " << grade << endl;
        }
};

int main(){
    int number, i;
    
    cout << "Enter the number of students you want to create: ";
    cin >> number;
    
    // Create array of Student objects
    Student *students = new Student[number];
    
    for (i = 0; i < number; i++){
        string reg, name;
        int marks;
        
        cout << "\nEnter details for student " << (i+1) << ":" << endl;
        cout << "Registration Number: ";
        cin >> reg;
        cout << "Name: ";
        cin >> name;
        cout << "Marks: ";
        cin >> marks;
        
        students[i] = Student(reg, name, marks);
    }
    
    // Display all students
    cout << "\n=== All Student Records ===" << endl;
    for (i = 0; i < number; i++){
        students[i].displayStudentDetails();
    }
    
    // Free allocated memory
    delete[] students;
    
    return 0;
}