#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "Pupil.h"
/*
int main(){
    Pupil x;
    x.set_pupil();
} */

Pupil::Pupil() {}

Pupil::~Pupil() {}

void Pupil::check(int condition){
    char all_layers[6] = {'a','b','c','d','e','f'};
    int all_class[3] = {1,2,3};
    bool run = true;
    if (condition == 1){
        while (run) {
            for (char all_layer : all_layers) {
                if (this->pupil_layer == all_layer) {
                    run = false;
                    break;
                }
            }
            if (run){
                cout << "Invalid Layer... Please try again" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> this->pupil_layer;
            }
        }
    }       // check layer

    if (condition == 2){
        while (run) {
            for(int all_clas : all_class){
                if(this->pupil_class == all_clas){
                    run = false;
                    break;
                }
            }
            if (run){
                cout << "Invalid Class... Please try again" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> this->pupil_class;
            }
        }
    }       // check class

}

Pupil Pupil::set_pupil() {
    cout << "For adding a new pupil, Please enter the next details:" << endl;

    set_person();       // get pupil name | func in class Person

    cout << "Layer (Enter only one character from a - f): " << endl;
    cin.clear();
    cin >> pupil_layer;
    check(1);

    cout << "Class (Enter only one digit from 1 - 3): " << endl;
    cin.clear();
    cin >> pupil_class;
    check(2);

    int NumOfSubjects;       // pupil number of subjects
    cin.clear();
    cout << "Please enter how many subjects the pupil take: (At least 1)" << endl;
    cin >> NumOfSubjects;

    cout << "Enter your hobbies: " << endl;
    ListOfSubject.resize(NumOfSubjects,vector<string>(2));
    for(int i=0;i<NumOfSubjects;i++) {
        cout << i + 1 << ". " << endl;          // print the number of the subject
        cout << "Subject: ";
        cin >> ListOfSubject[i][0];
        cout << "Grade: ";
        cin >> ListOfSubject[i][1];
        while (stoi(ListOfSubject[i][1]) < 0 || stoi(ListOfSubject[i][1]) > 100) {
            cout << "Invalid Grade... Please try again" << endl;
            cin.clear();
            cin >> ListOfSubject[i][1];
        }
    }
    return *this;
}

float Pupil::average(vector<vector<string>> list, int all_subjects){     // returning the pupil's average
    float average=0;

    for(int i=0;i<all_subjects;i++){
        average += stoi(list[i][1]);
    }
    average = average/(float)all_subjects;

    return average;
}

bool Pupil::outstanding() {     // check if the pupil is outstanding
    bool outstanding_aver = true;
    bool under_65 = true;
    int number = (int) this->ListOfSubject.size();
    float aver = average(this->ListOfSubject,number);

    if(aver < 85){          // check if pupil's average is under 85
        outstanding_aver = false;
    }
    for(int i=0; i<number;i++){
        if(stoi(this->ListOfSubject[i][1])<65){          // check if pupil's grades are under 65
            under_65 = false;
        }
    }
    return (outstanding_aver && under_65);
}

void Pupil::P_details() {
    cout << "The details of the pupil:" << endl;

    cout << "Name: " << get_person() << endl;       // pupil's full name

    int number =(int) this->ListOfSubject.size(); // number of subjects
    for(int i=0;i<number; i++){     // pupil's subjects and grades
        cout << i+1 << ". " << this->ListOfSubject[i][0] << " - " << this->ListOfSubject[i][1] << endl;
    }
    float aver = average(this->ListOfSubject,number);
    cout << "Average: " << aver << endl;        // pupil's average

    bool is_outstanding = outstanding();
    if(is_outstanding){
        cout << "The pupil is outstanding!" << endl;
    }
    if(!is_outstanding){
        cout << "The pupil isn't outstanding... " << endl;
    }

}

Pupil &Pupil::operator=(const Pupil &name) {
    this->pupil_class = name.pupil_class;
    this->pupil_layer = name.pupil_layer;
    this->First_name = name.First_name;
    this->Last_name = name.First_name;
    this->ListOfSubject = name.ListOfSubject;

    return *this;
}
