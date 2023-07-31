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
/*
int main(){
    Worker x;
    x.set_worker_name();
    x.set_worker_exec_seniority();
    x.set_worker_teac_seniority();

    x.W_details();
    return 0;
}
*/
int Worker::basis = 25;     // initial static value of basis

Worker::~Worker() {}

Worker::Worker() {

    seniority.resize(2);
    seniority[0] = "-";         //seniority[0] = "Teaching Seniority";
    seniority[1] = "-";         //seniority[1] = "Executive Seniority";

    // we can use the func stoi(seniority[x]) to copy in to an int
}

void Worker::set_worker_name() {
    set_person();       // get worker's name | func in class Person
}

void Worker::set_worker_teac_seniority() {
    cout << "Enter the years of teaching seniority: " << endl;
    cin.clear();
    cin >> seniority[0];       // set worker's teaching seniority
}

void Worker::set_worker_exec_seniority() {
    cout << "Enter the years of executive seniority: " << endl;
    cin.clear();
    cin >> seniority[1];       // set worker's executive seniority
}

void Worker::W_details() {

    cout << "Name: " << get_person() << endl;       // get worker's full name | func in class Person

    if(seniority[0] != "-" && seniority[1] == "-"){     // if a manager is sent to here we dont want to print Teaching Seniority.  ( it will be printed later in class Manager)
        cout << "Teaching Seniority: " << seniority[0] << endl;
    }
    if(seniority[1] != "-"){
        cout << "Executive Seniority: " << seniority[1] << endl;
    }
}

