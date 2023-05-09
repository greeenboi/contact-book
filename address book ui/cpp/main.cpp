#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include <exception>
using namespace std;

class Address_book{
public:
    string fname, lname, phone_num;
    void self_exit() {

        cout << "\n\n\n\t\tThank You for using Contact-Saver!";
        exit(1);
    }

    void help() {
        cout << "\tHelp Center" << endl << endl;
        cout << "When Prompted, user must enter a number from 1-5" << endl;
        cout << "The numbers each are assigned to a different function of the "
                "addresss book."
             << endl
             << endl
             << "The function assigned to each number is mentioned in the home page"
             << endl;
        cout << "Enter 0 to exit the program:";
        cout << endl << endl;
        int val;
        cin >> val;
        self_exit();
    }
    virtual bool check_digits(const string&)=0;
    virtual bool check_numbers(const string&)=0;
};
class false_digits:public exception{
public:
    const char* what() const throw(){
        return "incorrect number of digits";
    }
};

class false_number:public exception{
public:
    const char* what() const throw(){
        return "incorrect values entered";
    }
};
class verify: public Address_book{
public:
    bool check_digits(const string& x) {
        try {
            if (x.length() == 10){
                return true;
            }
            else {
                false_digits fd;
                throw fd;

            }
        }
        catch(exception& exc){
            cout<<exc.what();
            return false;
        }
    }

    bool check_numbers(const string& x) {
        bool check = true;
        try {
            for (char i: x) {
                if (!(int(i) >= 48 && int(i) <= 57)) {
                    check = false;
                    break;
                }
            }
            if (check)
                return true;

            else{
                false_number fn;
                throw fn;
            }

        }catch(exception& exp){
            cout<<exp.what();
            return false;
        }
        cout << endl << endl;
    }

};

class contact: public verify{

public:
    void view_all_contacts() {
        ifstream myfile("number.txt");
        if (myfile.is_open()) {
            string tp;
            while (getline(myfile, tp)) {
                cout << tp << "\n";
            }
        }
    }

    void addContact() {
        ofstream phone("number.txt", ios::app);

        cout << "\n\n\tEnter First Name : ";
        cin >> fname;
        cout << "\n\tEnter Last Name : ";
        cin >> lname;
        cout << "\n\tEnter Phone Number : ";
        cin >> phone_num;

        if (check_digits(phone_num)) {
            if (check_numbers(phone_num)) {
                if (phone.is_open()) {
                    phone << fname << " " << lname << " " << phone_num << endl;
                    cout << "\n\tContact saved successfully !";
                }
            }
        }
        cout << endl << endl;

        phone.close();
    }
    void searchContact() {
        bool found = false;
        ifstream myfile("number.txt");
        string keyword, fullname;
        cout << "\n\tEnter Name to search (first or last name only): ";
        cin >> keyword;
        fullname = fname + " " + lname;
        while (myfile >> fname >> lname >> phone_num) {
            if (keyword == fname || keyword == lname || keyword == fullname) {

                cout << "\n\n\n\t\tCONTACT DETAILS";
                cout << "\n\nFirst Name : " << fname;
                cout << "\nLast Name : " << lname;
                cout << "\nPhone Number : " << phone_num;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "\nNo such contact is found!";

        cout << endl << endl;
    }

};


int main() {
    int choice;
    contact contact;
    while (1) {
        cout << "\n\n\n\t\t\tCONTACT SAVER";
        cout << "\n\n\t1. Add Contact\n\t2. Search "
                "Contact\n\t3. Help\n\t4. View All Contacts\n\t5. Exit \n\t> ";
        cin >> choice;

        switch (choice) {
            case 1:
                contact.addContact();
                break;

            case 2:
                contact.searchContact();
                break;

            case 3:
                contact.help();
                break;

            case 4:
                contact.view_all_contacts();
                break;

            case 5:
                contact.self_exit();
                break;

            default:
                cout << "\n\n\tInvalid Input!";
        }
    }
    return 0;
}
