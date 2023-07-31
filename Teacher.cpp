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

#include "Teacher.h"
/*
int main(){
    Teacher x;
    x.start_set_teacher();
    x.printDetails();
}
*/
Teacher::Teacher(){}

Teacher::~Teacher(){}

void Teacher::start_set_teacher()
{
    cout << "For adding a new teacher, Please enter the next details:" << endl;
    Worker::set_worker_name();       // set teacher's name | func in class Worker
    set_teacher_det();      // set the rest of the teacher details

}

void Teacher::set_teacher_det() {
    cout << "How many classes does " << First_name << " teach?" << endl;
    cin.clear();
    cin >> m_numberOfClasses;       // set number of classes

    m_classNames.resize(m_numberOfClasses);     // resize the vector size to as many classes he teach
    cout << "Please enter them here:" << endl;
    for(int i=0;i<m_numberOfClasses;i++){
        cout << i+1 << ". ";
        cin.clear();
        cin >> m_classNames[i];             // set class name
    }
    Worker::set_worker_teac_seniority();       // set teacher's seniority | func in class Worker
}


float Teacher::Salary()
{
    return (float)basis * (1 + ((float)m_numberOfClasses/10)) + 300 * stoi(seniority[0]);
}

bool Teacher::outstanding()
{
    bool exel = false;
    if(m_numberOfClasses >= 5){
        exel = true;
    }
    return exel;
}

void Teacher::printClasses()
{
    cout << "All the classes that " << First_name << " teach are:" << endl;
    for(int i=0; i<m_numberOfClasses;i++){
        cout << i+1 << ". ";
        cout.clear();
        cout << m_classNames[i] << endl;       // print class name

    }
}

void Teacher::printDetails()
{
    cout << "The teacher's details are:" << endl;

    Worker::W_details();                 // get teacher's Worker details | func in class Worker
    printClasses();                      // print all the classes the teacher teach

    float salary = Salary();                       // get teacher's Salary
    cout << "Salary: " << salary << endl;

    bool is_outstanding = outstanding();          // check if teacher is outstanding as a teacher
    if(is_outstanding){
        cout << "Outstanding: Yes" << endl;
    }
    if(!is_outstanding){
        cout << "Outstanding: NO " << endl;
    }
}


