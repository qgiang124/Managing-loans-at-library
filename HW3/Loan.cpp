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
    dueDate = 0;
    recheck = 0;
}

Loan::Loan(int patronID, int bookID, int loanID, time_t dueDate, int recheckP) {
//    this->currPatron = currPatron;
//    this->usrBook = usrBook;
    this->loanID = loanID;
    this->bookID = bookID;
    this->patronID = patronID;
    this->dueDate = dueDate;
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

void Loan::SetDueDate(time_t dateToSet) {
    dueDate = dateToSet;
}

void Loan::SetRecheck(int recheckP) {
    recheck = recheckP;
}

int Loan::GetLoanID() {
    return loanID;
}

int Loan::GetPatronID() {
    return patronID;
}

int Loan::GetBookID() {
    return bookID;
}

time_t Loan::GetDueDate() {
    return dueDate;
}

int Loan::GetRecheck() {
    return recheck;
}

void Loan::PrintLoan() {
    cout << left << setw(20) << "Loan ID: " << loanID << endl;
    cout << left << setw(20) << "Book ID: " << bookID << endl;
    cout << left << setw(20) << "Patron ID: " << patronID << endl;
    cout << left << setw(20) << "Due date: " << dueDate << endl;
}
