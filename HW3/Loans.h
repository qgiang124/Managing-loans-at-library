//
//  Loans.h
//  HW3
//
//  Created by Giang Tran on 4/4/22.
//

#ifndef Loans_h
#define Loans_h

#include "Loan.h"
#include "Patrons.h"
#include "Books.h"
#include <vector>
#include <ctime>
using namespace std;

const int FINE_RATE = 0.25;
const int CHECK_OUT_PERIOD = 864000; //10 days

class Loans {
private:
    int count = 0;
    int ID = 0;
    vector<Loan> listLoan;
//    time_t checkOutTime;
    
public:
    void CheckOutBook(Patron* pat, Book* book);
    void CheckInBook(Patron* pat, Book* book);
    void ListOverdue();
    void ListAllBookFor(Patron* pat, Books* books);
    void LoadLoan();
    void CheckOverDue(Loan* loan, Patron &patron);
    void RecheckBook(Loan* loan);
    void ReportLost(Patron* pat, Book* book);
    void StoreLoan();
};
#endif /* Loans_h */
