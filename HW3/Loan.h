//
//  Loan.h
//  HW3
//
//  Created by Giang Tran on 3/28/22.
//

#ifndef Loan_h
#define Loan_h

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Loan {
private:
//    Book usrBook;
//    Patron currPatron;  //current patron
    int loanID;
    int bookID;
    int patronID;
    time_t dueDate;
    int recheck; //0 if not recheck, 1 otherwise
    
public:
    Loan();
    Loan(int loanID, int bookID, int patronID, time_t dueDate, int recheckP);
    void SetLoanID(int LIDToSet);
    void SetBookID(int BIDToSet);
    void SetPatronID(int PIDToSet);
    void SetDueDate(time_t dateToSet);
    void SetRecheck(int recheckP);
    int  GetLoanID();
    int  GetPatronID();
    int  GetBookID();
    time_t  GetDueDate();
    int  GetRecheck();
    void PrintLoan();
};

#endif /* Loan_h */
