//
//  Patron.cpp
//  HW3
//
//  Created by Giang Tran on 4/12/22.
//

#include "Patron.h"
using namespace std;

Patron::Patron(){
    name = "none";
    IDNum = 0;
    fineBalance = 0;
    numBooksOut = 0;
}

Patron::Patron(string name, int IDNum, double fineBalance, int numBooksOut) {
    this->name = name;
    this->IDNum = IDNum;
    this->fineBalance = fineBalance;
    this->numBooksOut = numBooksOut;
}

void Patron::SetPatName(string nameToSet) {
    name = nameToSet;
}

void Patron::SetPatID(int IDToSet) {
    IDNum = IDToSet;
}

void Patron::SetFineBal(double amountToSet) {
    fineBalance = amountToSet;
}

void Patron::SetNumBooksOut(int numToSet) {
    numBooksOut = numToSet;
}

void Patron::AddFine(int amount) {
    fineBalance += amount;
}

void Patron::PayFine(int amount) {
    fineBalance -= amount;
}

string Patron::GetPatName() {
    return name;
}

int Patron::GetPatID() {
    return IDNum;
}

double Patron::GetFineBalance() {
    return fineBalance;
}

int Patron::GetNumBooksOut() {
    return numBooksOut;
}

void Patron::PrintPatron() {
    cout << "---------------PATRON DETAILS---------------\n";
    cout << left << setw(20) << "Patron's name:" << name << endl;
    cout << left << setw(20) << "Patron's ID:" << IDNum << endl;
    cout << left << setw(20) << "Fine balance: " << fineBalance << endl;
    cout << left << setw(20) << "Current of books out: " << numBooksOut << endl;
}
