/* Assignment C++: 3
Author: Tal Levy, ID: 314966359
Author2: Guy Zalsman, ID:312488794
*/
#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "Worker.h"

#ifndef PERSON_CPP_TEACHER_H
#define PERSON_CPP_TEACHER_H


class Teacher :
        public Worker
{
protected:
    vector<string> m_classNames;
    unsigned int m_numberOfClasses;

public:
    Teacher();
    ~Teacher();
    void start_set_teacher();
    void set_teacher_det();
    float Salary();
    bool outstanding() ;
    void printClasses();
    void printDetails();
};


#endif //PERSON_CPP_TEACHER_H
