//
//  Patrons.cpp
//  HW3
//
//  Created by Giang Tran on 4/23/22.
//

#include "Patrons.h"
#include <fstream>
using namespace std;

void Patrons::AddPatron(Patron currPatron) {
    listPatron.push_back(currPatron);
    IncCount();
}

void Patrons::EditPatron(int patronID) {
    unsigned int patPos; //patron's position in patron list
    int choice;
    Patron* currPatron;
    string newName;
    int newID;
    double newBalance;
    int newNumBook;
    
    patPos = SearchPatron(patronID);
    currPatron = &listPatron[patPos];
    
    if (FoundPatron(patronID)){
        cout << "What do you want to update? \n";
        cout << "1. Name \n2. ID number \n3. Fine balance \n4. Current number of books out\n";
        cin  >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the new name: ";
                getline(cin >> ws, newName);
                currPatron->SetPatName(newName);
                break;
            case 2:
                cout << "Enter the new ID: ";
                cin >> newID;
                currPatron->SetPatID(newID);
                break;
            case 3:
                cout << "Enter the new fine balance: ";
                cin >> newBalance;
                currPatron->SetFineBal(newBalance);
                break;
            case 4:
                cout << "Enter the new current number of books out: ";
                cin >> newNumBook;
                currPatron->SetNumBooksOut(newNumBook);
                break;
        }
        
        cout << "Updated!\n";
    }
}

void Patrons::DeletePatron(int patronID) {
    unsigned int patPos;
    patPos = SearchPatron(patronID);
    
    if (FoundPatron(patronID)){
        listPatron.erase(listPatron.begin() + patPos);
        cout << "Deleted!\n";
    }
    DecCount();
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
    
//    vector<Patron>::iterator iter;
//    for (iter = listPatron.begin(); iter != listPatron.end(); iter++) {
//        if ((*iter).GetPatID() == patronID) {
//            return (*iter);
//        }
//    }
//    return;
}

void Patrons::PayFines(int patronID) {
    double amountPay;
    Patron currPatron;
    unsigned int patPos = SearchPatron(patronID);
    currPatron = listPatron[patPos];
    
    cout << "Patron: " << currPatron.GetPatName() << endl;
    cout << "Current fine balance: " << currPatron.GetFineBalance() << endl;
    
    cout << "Amount pay today: ";
    cin  >> amountPay;
    
    currPatron.PayFine(amountPay);
    cout << currPatron.GetFineBalance() << " were paid. Current fine balance is: " << currPatron.GetFineBalance() << endl;
}

void Patrons::PrintAPatron(int patronID) {
    unsigned int patPos = SearchPatron(patronID);
    
    if (FoundPatron(patronID)) {
        listPatron[patPos].PrintPatron();
    }
}

void Patrons::PrintAllPatrons() {
    vector<Patron>::iterator iter;
    for (iter = listPatron.begin(); iter != listPatron.end(); iter++) {
        (*iter).PrintPatron();
    }
}

void Patrons::LoadPatron() {
    Patron currPatron;
    int    numPatron;
    ifstream inFS;
    string name;
    int    ID;
    double fine;
    int    numBookOut;
    cout << "Giang";
    inFS.open("patrons.dat");
    if (!inFS.is_open()) {
        cout << "Could not open file patrons.dat" << endl;
        exit(EXIT_FAILURE);
    }
    
    //read the number of patron from the first lind in patrons.dat
    inFS >> numPatron; inFS.ignore();
    
    for (int i = 0; i < numPatron; i++) {
        getline(inFS, name, ',');
        inFS >> ID;   inFS.ignore(256, ',');
        inFS >> fine; inFS.ignore(256, ',');
        inFS >> numBookOut; inFS.ignore();
        
        currPatron.SetPatName(name);
        currPatron.SetPatID(ID);
        currPatron.SetFineBal(fine);
        currPatron.SetNumBooksOut(numBookOut);
        
        listPatron.push_back(currPatron);
        count++;
    }
    inFS.close();
}

bool Patrons::FoundPatron(int patronID) {
    unsigned int patPos ; //postion of the patron in list
    
    patPos = SearchPatron(patronID);
    if (patPos == -1) {
        cout << "Patron not found!\n";
        return false;
    }
    
    return true;
}
