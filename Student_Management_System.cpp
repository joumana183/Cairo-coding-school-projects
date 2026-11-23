#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student{
    private:
        string name;
        int id;
        vector<string> courses;
    public:
        Student(string n, int i): name(n), id(i){}
        string getName(){
            return name;
        }
        int getId(){
            return id;
        }
        void addcourse(string c){
            courses.push_back(c);
        }
        void deletecourse(string c){
            for(int i=0; i<courses.size(); i++){
                if(courses[i] == c){
                    courses.erase(courses.begin()+i);
                    break;
                }
            }
        }

        bool checkCourse(string c){
            for(int i = 0; i < courses.size(); i++){
                if(courses[i] == c){
                    return true;
                }
            }
            return false;
        }

        void displayStudent(){
            cout<<"Name: " <<name <<endl;
            cout<<"ID: " <<id <<endl;
            cout<<"Courses: ";
            for(int i=0; i<courses.size(); i++){
                cout<<courses[i]<<" ";
            }
            cout<<endl;
        }
};

void addStudent(vector<Student>& students){
    string name;
    int id;
    cout<<"Enter student's name: ";
    cin.ignore();
    getline(cin, name);
    cout<<endl;
    cout<<"Enter student's ID: ";
    cin>>id;
    cout<<endl;
    for(int i = 0; i < students.size(); i++){
        if(students[i].getId() == id){
            cout << "This ID already exists!" << endl;
            return;
        }
    }
    Student s(name, id);
    students.push_back(s);
    cout<<"Student " <<name <<" is added" <<endl; 
}

void deleteStudent(vector<Student>& students){
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    for(int i=0; i<students.size(); i++){
        if(students[i].getId() == id){
            string name = students[i].getName();
            students.erase(students.begin()+i);
            cout<<"Student " <<name <<" is deleted" <<endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void addCourse(vector<Student>& students){
    int id;
    string course;
    cout<<"Enter student's ID: ";
    cin>>id;
    cout<<endl;
    cout<<"Enter course name: ";
    cin.ignore();
    getline(cin, course);
    for(int i=0; i<students.size(); i++){
        if(students[i].getId() == id){
            students[i].addcourse(course);
            cout<<"Course " <<course <<" added to " <<students[i].getName() <<endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void deleteCourse(vector<Student>& students){
    int id;
    string course;
    cout<<"Enter student's ID: ";
    cin>>id;
    cout<<endl;
    cout<<"Enter course name: ";
    cin.ignore();
    getline(cin, course);
    for(int i = 0; i < students.size(); i++){
        if(students[i].getId() == id){
            if(students[i].checkCourse(course)){
                students[i].deletecourse(course);
                cout << "Course \"" << course << "\" deleted from " << students[i].getName() << endl;
            }
            else{
                cout << "Course not found!" << endl;
            }
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void displayAllStudents(vector<Student>& students){
    if(students.empty()){
        cout << "No students found!" << endl;
        return;
    }
    for(int i=0; i<students.size(); i++){
        students[i].displayStudent();
        cout<<endl;
    }
}

void displayMenu(){
    cout << "=== Student Management System ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Add Course to Student" << endl;
    cout << "4. Delete Course from Student" << endl;
    cout << "5. Display All Students" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";
}

int main(){
    int choice;
    vector<Student> students;
    do{
        displayMenu();
        cin>>choice;
        switch(choice){
            case 1:
                addStudent(students);
                break;
            case 2:
                deleteStudent(students);
                break;
            case 3:
                addCourse(students);
                break;
            case 4:
                deleteCourse(students);
                break;
            case 5:
                displayAllStudents(students);
                break;
            case 6:
                cout<<"goodbye!" <<endl;
                break;
            default:
                cout<<"Invalid choice" <<endl;
        }
    } while(choice!=6);
    return 0;
}