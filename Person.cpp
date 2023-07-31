#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "Person.h"

Person::Person() {}

Person::~Person() {}

string Person::get_person(){
    string temp(string(First_name) + " " + Last_name);      // insert the first and last name into one variable

    return temp;
}

void Person::set_person() {
    cout << "First name: " << endl;
    cin.clear();
    First_name = get_input();

    cout << "Last name: " << endl;
    //    cin.ignore(1000,'\n');
    cin.clear();
    Last_name = get_input();

}

char * Person::get_input(){
    string user_input;
    user_input = "";

    getline(cin, user_input);           // get a string from user
    user_input[0] = toupper(user_input[0]);
    int n = user_input.length();
    char* temp = new char[n+1];
    strcpy(temp, user_input.c_str());// copy the string (user_input) as a char*

    return temp;
}

void Person::Per_details(){
    cout << First_name << " " << Last_name <<endl;      // print Person's full name
}

Person &Person::operator=(const Person &name) {

    if (name.First_name != NULL) {
        // copy the string to the new item
        this->First_name = name.First_name;
    }
    if (name.Last_name != NULL) {
        // copy the string to the new item
        this->Last_name = name.Last_name;
    }
    return *this;
}
