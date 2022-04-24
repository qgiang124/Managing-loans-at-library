//
//  Patrons.cpp
//  HW3
//
//  Created by Giang Tran on 4/23/22.
//

#include "Patrons.h"
using namespace std;

void Patrons::AddPatron(Patron currPatron) {
    listPatron.push_back(currPatron);
}

void Patrons::EditPatron(int patronID) {
    unsigned int patPos = NULL; //patron's position in patron list
    int choice;
    Patron* currPatron;
    
    patPos = SearchPatron(patronID);
    currPatron = &listPatron[patPos];
    
    if (patPos == -1) {
        cout << "Patron not found! Please try again." << endl;
    }
    else {
        cout << "What do you want to update? \n";
        cout << "1. Name \n2. ID number \n3. Fine balance \n4. Current number of books out\n";
        cin  >> choice;
    }
}

void Patrons::DecCount() {
    count--;
}

void Patrons::IncCount() {
    count++;
}

int Patrons::GetCount() {
    return count;
}

int Patrons::SearchPatron(int patronID) {
    unsigned int pos = 0; //the posititon of the needed-to-look patron
    vector<Patron>::iterator iter;
    for (iter = listPatron.begin(); iter != listPatron.end(); iter++) {
        if ((*iter).GetPatID() == patronID) {
            return pos;
        }
        pos++;
    }
    return -1;
}
