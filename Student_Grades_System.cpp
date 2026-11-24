#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Subject {
    string name;
    double grade;
public:
    Subject(const string& n, double g) : name(n), grade(0){
        setGrade(g);
    }
    string getName() const{ 
        return name;
    }
    double getGrade() const{
        return grade;
    }
    void setGrade(double g){
        if (g < 0 || g > 100){
            cout << "Invalid grade!" << endl;
            return;
        }
        grade = g;
    }
};

class Student{
    private:
        string name;
        int id;
        vector<Subject> subjects;
public:
    Student(string n, int i) : name(n), id(i) {}
    string getName() const{
        return name;
    }
    int getId() const{
        return id;
    }
    void addSubject(const Subject& s){
        subjects.push_back(s);
    }

    double getAverage() const{
        if(subjects.empty()){
            return 0;
        }
        double avg=0;
        for(int i=0; i<subjects.size(); i++){
            avg+=subjects[i].getGrade();
        }
        return avg/subjects.size();
    }

    char getLetterGrade() const{
        if(subjects.empty()) return '-';
        double average = getAverage();
        if(average >= 90) return 'A';
        else if(average >= 80) return 'B';
        else if(average >= 70) return 'C';
        else if(average >= 60) return 'D';
        else if(average >= 50) return 'E';
        else return 'F';
    }

    void displayReport() const{
        cout << "Student: " << name << endl;
        for(int i = 0; i < subjects.size(); i++) {
            cout << subjects[i].getName() << ": " << subjects[i].getGrade() << endl;
        }
        if(subjects.empty()) {
            cout << "No grades recorded yet." << endl;
            return;
        }
        cout << "Average: " << getAverage() << " | Grade: " << getLetterGrade() << endl;
    }

    bool hasSubject(const string& subjectName) const{
        for(int i = 0; i < subjects.size(); i++) {
            if(subjects[i].getName() == subjectName) {
                return true;
            }
        }
        return false;
    }
};

void addStudent(vector<Student>& students) {
    string name;
    int id;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter student ID: ";
    cin >> id;
    for(int i = 0; i < students.size(); i++) {
        if(students[i].getId() == id) {
            cout << "This ID already exists!" << endl;
            return;
        }
    }
    Student s(name, id);
    students.push_back(s);
    cout << "Student \"" << name << "\" added." << endl;
}

void recordGrade(vector<Student>& students) {
    string name;
    string subject;
    double grade;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    for(int i = 0; i < students.size(); i++) {
        if(students[i].getName() == name) {
            cout << "Enter subject: ";
            getline(cin, subject);
            if(students[i].hasSubject(subject)) {
                cout << "This subject already exists for this student!" << endl;
                return;
            }
            cout << "Enter grade: ";
            cin >> grade;
            if(grade < 0 || grade > 100) {
                cout << "Invalid grade!" << endl;
                return;
            }
            Subject s(subject, grade);
            students[i].addSubject(s);
            cout << "Grade recorded." << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void displayClassReport(const vector<Student>& students) {
    if(students.empty()) {
        cout << "No students registered!" << endl;
        return;
    }
    double classAvg = 0;
    for(int i = 0; i < students.size(); i++) {
        students[i].displayReport();
        classAvg += students[i].getAverage();
        cout << "--------------------" << endl;
    }
    classAvg /= students.size();
    cout << "Class Average: " << classAvg << endl;
}

void displayMenu(){
    cout<<"=== Student Grades System ===\n";
    cout<<"1. Add Student\n";
    cout<<"2. Record Grade\n";
    cout<<"3. Display Report\n";
    cout<<"4. Exit\n";
    cout<<"Choose an option: \n";
}

int main(){
    vector<Student> students;
    int choice;
    do{
        displayMenu();
        cin>>choice;
        switch(choice) {
            case 1:
                addStudent(students);
                break;

            case 2:
                recordGrade(students);
                break;

            case 3:
                displayClassReport(students);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 4);
    return 0;
}