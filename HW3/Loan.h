//
//  Loan.h
//  HW3
//
//  Created by Giang Tran on 3/28/22.
//

#ifndef Loan_h
#define Loan_h

#include "Book.h"
#include "Patron.h"
#include <ctime>
using namespace std;

class Loan {
private:
    Book usrBook;
    Patron currPatron;  //current patron
    int loanID;
    string dueDate;
    string currLoanStatus;
    
public:
    Loan();
    Loan(Patron currPatron, Book usrBook, int loanID, string dueDate, string currLoanStatus);
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
