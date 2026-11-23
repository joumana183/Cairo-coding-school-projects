#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Patient{
    private:
        string name;
        int age;
        string doctor;
    public:
        Patient(string n, int a, string d="Not assigned"): name(n), age(a), doctor(d) {
            cout<<"Patient \"" <<name <<"\" added" <<endl;
        }
        string getName(){
            return name;
        }
        string getDoctor(){
            return doctor;
        }
        int getAge(){
            return age;
        }
        void setDoctor(string s){
            doctor=s;
        }
        void displayPatient(){
            cout<<"Patient: " <<name <<" | Age: " <<age <<" | Doctor: " <<doctor <<endl; 
        }
};

class Hospital{
    private:
        vector<Patient> patients;
    public:
        void addPatient(){
            string name;
            int age;
            cout<<"Enter patient name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter age: ";
            cin>>age;
            Patient p(name, age);
            patients.push_back(p);
        }
        void assignDoctor(){
            string name, doctor;
            cout<<"Enter patient name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter doctor name: ";
            getline(cin, doctor);
            for(int i=0; i<patients.size(); i++){
                if(patients[i].getName()==name){
                    patients[i].setDoctor(doctor);
                    cout<<name <<" assigned to " <<doctor <<endl;
                    return;
                }
            }
            cout<<"Patient not found!" <<endl;
        }
        void searchPatient(){
            string name;
            cout<<"Enter patient name: ";
            cin.ignore();
            getline(cin, name);
            for(int i=0; i<patients.size(); i++){
                if(patients[i].getName()==name){
                    patients[i].displayPatient();
                    return;
                }
            }
            cout<<"Patient not found!" <<endl;
        }
        void displayAllPatients(){
            if(patients.empty()){
                cout<<"No patients!" <<endl;
                return;
            }
            for(int i=0; i<patients.size(); i++){
                patients[i].displayPatient();
            }
        }
};

void displaymenu(){
    cout<<"=== Hospital System (draft) ===\n";
    cout<<"1. Add Patient\n";
    cout<<"2. Assign Doctor\n";
    cout<<"3. Search Patient\n";
    cout<<"4. Display All Patients\n";
    cout<<"5. Exit\n";
    cout<<"Choose an option:\n";
}

int main(){
    Hospital h;
    int choice;
    do{
        displaymenu();
        cin>>choice;
        switch(choice){
            case 1:
                h.addPatient();
                break;
            case 2:
                h.assignDoctor();
                break;
            case 3:
                h.searchPatient();
                break;
            case 4:
                h.displayAllPatients();
                break;
            case 5:
                cout<<"GoodBye!" <<endl;
                break;
            default:
                cout<<"Invalid choice!" <<endl;
        }
    } while(choice != 5);
    return 0;
}