#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Inventory{
    private:
        string name;
        int quantity;
        double price;
    public:
        Inventory(string n, int q, double p): name(n), quantity(q), price(p){}
        string getName(){
            return name;
        }
        int getQuantity(){
            return quantity;
        }
        double getPrice(){
            return price;
        }
        bool updateQuantity(int change){
            if(quantity + change >= 0) {
                quantity += change;
                return true;
            }
            return false;
        }
        void displayItem(){
            double total = quantity * price;
            cout<<"Name: " <<name <<" | Quantity: " <<quantity <<" | Price: " <<price << " EGP"
            <<" | Total: " <<total <<" EGP" <<endl;
        }
};

class Management{
    private:
        vector<Inventory> items;
    public:
        void addItem(){
            string n;
            int q;
            double p;
            cout<<"Enter item name: ";
            cin.ignore();
            getline(cin, n);
            cout<<"Enter quantity: ";
            cin>>q;
            cout<<"Enter unit price: ";
            cin>>p;
            if(q < 0 || p < 0){
            cout << "Invalid quantity or price!" << endl;
            return;
            }
            Inventory i(n,q,p);
            items.push_back(i);
             cout<<"Item \"" <<n <<"\" added" <<endl;
        }
        void removeItem(){
            string n;
            cout<<"Enter item name: ";
            cin.ignore();
            getline(cin, n);
            for(int i=0 ; i<items.size() ; i++){
                if(items[i].getName() == n){
                    items.erase(items.begin()+i);
                    cout<<"Item \"" <<n <<"\" removed" <<endl;
                    return;
                }
            }
            cout<<"Item is not found!" <<endl;
        }
        void updateQuantity(){
            string n;
            int q;
            cout<<"Enter item name: ";
            cin.ignore();
            getline(cin, n);
            cout<<"Enter quantity change: ";
            cin>>q;
            for(int i=0; i<items.size(); i++){
                if(items[i].getName() == n){
                   if(items[i].updateQuantity(q)){
                    cout << "Updated quantity: " << items[i].getQuantity() << endl;
                }
                else{
                    cout << "Invalid quantity!" << endl;
                }
                return; 
                }
            }
            cout<<"Item is not found!" <<endl;
        }
        void searchItem(){
            string n;
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, n);
            for(int i = 0; i < items.size(); i++){
                if(items[i].getName() == n){
                    items[i].displayItem();
                    return;
                }
            }
            cout << "Item not found!" << endl;
        }
        void displayInventory(){
            if(items.empty()){
                cout << "Inventory is empty!" << endl;
                return;
            }
            double totalPrice=0;
            cout<<"====All Inventory====\n";
            for(int i=0; i<items.size(); i++){
                totalPrice += items[i].getQuantity() * items[i].getPrice();
                items[i].displayItem();
            }
            cout << "Total Inventory Value: " <<totalPrice << " EGP" << endl;
        }
};

void displaymenu(){
    cout << "\n=== Inventory Management System ===" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Update Quantity" << endl;
    cout << "4. Search Item" << endl;
    cout << "5. Display Inventory" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";
}

int main(){
    Management management;
    int choice;
    do{
        displaymenu();
        cin>>choice;
        switch(choice){
            case 1:
                management.addItem();
                break;

            case 2:
                management.removeItem();
                break;

            case 3:
                management.updateQuantity();
                break;

            case 4:
                management.searchItem();
                break;

            case 5:
                management.displayInventory();
                break;

            case 6:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }while(choice != 6);
    return 0;
}