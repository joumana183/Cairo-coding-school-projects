#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Book{
    private:
        string title;
        string author;
        bool availability;
    public:
        Book(string t, string a): title(t), author(a), availability(true){}
        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
        bool getAvailability(){
            return availability;
        }
        void setAvailability(bool a){
            availability = a;
        }
        void displayBook(){
            cout<<"Title: " <<title <<" | Author: "  <<author 
            <<" | Status: " <<(availability ? "Available" : "Borrowed") <<endl;
        }
};

class Member{
    private:
        string name;
        vector<string> Borrowed;

    public:
        Member(string n="user 1"): name(n) {}
        void borrowBook(string title){
            Borrowed.push_back(title);
        }
        void returnBook(string title){
            for(int i = 0; i < Borrowed.size(); i++){
                if(Borrowed[i] == title){
                    Borrowed.erase(Borrowed.begin() + i);
                    return;
                }
            }
        }
};

void addBook(vector<Book>& books){
    string title, author;
    cout<<"Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout<<"Enter book author: ";
    getline(cin, author);
    Book b(title, author);
    books.push_back(b);
    cout<<"Book \"" <<title <<"\" is added" <<endl; 
}

void removeBook(vector<Book>& books){
    string title;
    cout<<"Enter book title: ";
    cin.ignore();
    getline(cin, title);
    for(int i=0; i<books.size(); i++){
        if(books[i].getTitle()==title){
            if(books[i].getAvailability() == false){
                cout << "Cannot remove a borrowed book!" << endl;
                return;
            }
            books.erase(books.begin()+i);
            cout<<"Book \"" <<title <<"\" is removed" <<endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void borrowBook(vector<Book>& books, Member& m1){
    string title;
    cout<<"Enter book title to borrow: ";
    cin.ignore();
    getline(cin, title);
    for(int i=0; i<books.size(); i++){
        if(books[i].getTitle()==title){
            if(books[i].getAvailability()== true){
                books[i].setAvailability(false);
                cout<<"\"" <<title <<"\" borrowed successfully" <<endl;
                m1.borrowBook(title);
            }
            else{
                cout<<"Book is not available!" <<endl;
            }
            return;
        }
    }
    cout<<"Book not found!" << endl;
}

void returnBook(vector<Book>& books, Member& m1){
    string title;
    cout<<"Enter book title to return: ";
    cin.ignore();
    getline(cin, title);
    for(int i=0; i<books.size(); i++){
        if(books[i].getTitle()==title){
            if(books[i].getAvailability()== false){
                books[i].setAvailability(true);
                cout<<"\"" <<title <<"\" is returned successfully" <<endl;
                m1.returnBook(title);
            }
            else{
                cout<<"Book is already available!" <<endl;
            }
            return;
        }
    }
    cout<<"Book not found!" << endl;
}

void searchBook(vector<Book>& books){
    string search;
    cout << "Enter book title or author to search: ";
    cin.ignore();
    getline(cin, search);
    bool found = false;
    for(int i = 0; i < books.size(); i++){
        if(books[i].getTitle() ==search || books[i].getAuthor() ==search){
            if(!found){
                cout << "\n=== Search Results ===" << endl;
            }
            books[i].displayBook();
            found = true;
        }
    }
    if(!found){
        cout << "No matching books found!" << endl;
    }
}

void displayAllBooks(vector<Book>& books){
    if(books.empty()){
        cout << "No books in the library!" << endl;
        return;
    }
    cout << "\n=== All Books ===" << endl;
    for(int i=0; i<books.size(); i++){
        books[i].displayBook();
    }
}

void displayMenu(){
    cout << "\n=== Library Management System ===" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Remove Book" << endl;
    cout << "3. Borrow Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Search Book" << endl;
    cout << "6. Display All Books" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose an option: ";
}

int main(){
    int choice;
    vector<Book> books;
    Member m1;
    do{
        displayMenu();
        cin>>choice;
        switch(choice){
            case 1:
                addBook(books);
                break;
            case 2:
                removeBook(books);
                break;
            case 3:
                borrowBook(books, m1);
                break;
            case 4:
                returnBook(books, m1);
                break;
            case 5:
                searchBook(books);
                break;
            case 6:
                displayAllBooks(books);
                break;
            case 7:
                cout<<"GoodBye!" <<endl;
                break;
            default:
                cout<<"Invalid choice!" <<endl;
        }
    } while(choice != 7);
    return 0;
}