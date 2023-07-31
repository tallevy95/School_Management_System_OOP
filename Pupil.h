#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "Person.h"

#ifndef EXE_3_C___PUPIL_H
#define EXE_3_C___PUPIL_H


class Pupil: public Person {
protected:
    char pupil_layer;
    int pupil_class;
    vector<vector<string>> ListOfSubject;

public:
    Pupil();
    ~Pupil();

    float average(vector<vector<string>> list, int all_subjects);
    Pupil set_pupil();
    bool outstanding();
    void P_details();
    void check(int condition);

    Pupil& operator = (const Pupil &name);

    };


#endif //EXE_3_C___PUPIL_H
