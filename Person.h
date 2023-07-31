#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#ifndef EXE_3_C___PERSON_H
#define EXE_3_C___PERSON_H


class Person {
protected:
    char* First_name;
    char* Last_name;

    char* get_input();

public:
    Person();   // default Constructor

    ~Person();   // Destructor

    virtual bool outstanding() = 0;
    void set_person();
    string get_person();
    void Per_details();


    Person& operator=(const Person &name);

};


#endif //EXE_3_C___PERSON_H
