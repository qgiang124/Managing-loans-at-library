//
//  Loan.cpp
//  HW3
//
//  Created by Giang Tran on 4/12/22.
//

#include "Loan.h"

Loan::Loan(){
    loanID = 0;
    dueDate = "no data";
    currLoanStatus = "none";
}

Loan::Loan(Patron currPatron, Book usrBook, int loanID, string dueDate, string currLoanStatus) {
    this->currPatron = currPatron;
    this->usrBook = usrBook;
    this->loanID = loanID;
    this->dueDate = dueDate;
    this->currLoanStatus = currLoanStatus;
}

void Loan::SetLoanID(int LIDToSet) {
    l
}
