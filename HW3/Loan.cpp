//
//  Loan.cpp
//  HW3
//
//  Created by Giang Tran on 4/12/22.
//

#include "Loan.h"

Loan::Loan(){
    loanID = 0;
    bookID = 0;
    patronID = 0;
    dueDate = "no data";
    currLoanStatus = "none";
}

Loan::Loan(int patronID, int bookID, int loanID, string dueDate, string currLoanStatus) {
//    this->currPatron = currPatron;
//    this->usrBook = usrBook;
    this->loanID = loanID;
    this->bookID = bookID;
    this->patronID = patronID;
    this->dueDate = dueDate;
    this->currLoanStatus = currLoanStatus;
}

void Loan::SetLoanID(int LIDToSet) {
    loanID = LIDToSet;
}

void Loan::SetBookID(int BIDToSet) {
    bookID = BIDToSet;
}

void Loan::SetPatronID(int PIDToSet) {
    patronID = PIDToSet;
}

void Loan::SetDueDate(string dateToSet) {
    dueDate = dateToSet;
}

void Loan::SetLoanStatus(string statToSet) {
    currLoanStatus = statToSet;
}

void Loan::PrintLoan() {
    cout << left << setw(20) << "Loan ID: " << loanID << endl;
    cout << left << setw(20) << "Book ID: " << bookID << endl;
    cout << left << setw(20) << "Patron ID: " << patronID << endl;
    cout << left << setw(20) << "Due date: " << dueDate << endl;
    cout << left << setw(20) << "Current loan's status: " << currLoanStatus << endl;
}
