#include<iostream>
#include <string>
using namespace std;

class Account{
    private:
        string owner;
        long long Balance;
    public:
        Account(string o="user 1" ,long long B=0): owner(o), Balance(B){}
        void deposit(long long value){
            if(value>0){
                Balance+=value;
                cout<<"Deposited " <<value <<" EGP. New balance: " <<Balance <<" EGP" <<endl;
            }
            else{
                cout<<"Error: deposit amount must be positive. Current balance: " <<Balance <<" EGP" <<endl;
            }
        }
        void withdraw(long long value){
            if (value <= 0) {
                cout << "Error: withdrawal amount must be positive." << endl;
            }
            else if (value > Balance) {
                cout << "Error: insufficient funds. Current balance: " << Balance << " EGP" << endl;
            }
            else {
                Balance -= value;
                cout << "Withdrawn " << value << " EGP. New balance: " << Balance << " EGP" << endl;
            }
        }
        long long getBalance(){
            return Balance;
        }

};

void displayMenu(){
    cout << "\n=== Bank System ===" <<endl;
    cout << "1. Deposit" <<endl;
    cout << "2. Withdraw" <<endl;
    cout << "3. Check Balance" <<endl;
    cout << "4. Exit" <<endl;
}

int main(){
    int choice;
    long long value;
    displayMenu();
    Account a1;
    do{
        cout << "Choose an option: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter amount to deposit: ";
                cin>>value;
                a1.deposit(value);
                break;
            case 2:
                cout<<"Enter amount to withdraw: ";
                cin>>value;
                a1.withdraw(value);
                break;
            case 3:
                cout<<"Current balance: " <<a1.getBalance() <<" EGP" <<endl;
                break;
            case 4:
                cout<<"Goodbye!" <<endl;
                break;
            default:
                cout<<"Invalid choice" <<endl;
        }
    } while(choice!=4);
    return 0;
}