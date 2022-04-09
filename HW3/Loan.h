//
//  Loan.h
//  HW3
//
//  Created by Giang Tran on 3/28/22.
//

#ifndef Loan_h
#define Loan_h

#include "Book.h"
using namespace std;

class Loan {
private:
    Book usrBook;
    Patron currPatron;  //current patron
    int loanID;
    string dueDate;
    string currLoanStatus;
    
public:
    void SetLoanID(int LIDToSet);
    void SetDueDate(string dateToSet);
    void SetLoanStatus(string statToSet);
    int  GetLoanID();
    int  GetPatronID();
    int  GetBookID();
    int  GetDueDate();
    string GetCurrLoanStatus();
};

#endif /* Loan_h */
