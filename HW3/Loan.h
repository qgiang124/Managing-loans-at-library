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
    
    
public:
    Loan();
    Loan(int loanID, int bookID, int patronID, time_t dueDate);
    void SetLoanID(int LIDToSet);
    void SetBookID(int BIDToSet);
    void SetPatronID(int PIDToSet);
    void SetDueDate(time_t dateToSet);
    int  GetLoanID();
    int  GetPatronID();
    int  GetBookID();
    time_t  GetDueDate();
    void PrintLoan();
};

#endif /* Loan_h */
