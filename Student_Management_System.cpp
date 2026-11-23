#include<iostream>
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

void addstudent(vector<Student>& students){
    string name;
    int id;
    cout<<"Enter student name: ";
    cin>>name;
    cin>>id;
    Student s(name, id);
    students.push_back(s);
    cout<<"Student /"" <<name <<"added" <<endl; 
}

int main(){
    string name;
    vector<Student> students;

    return 0;
}