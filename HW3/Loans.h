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
    void CheckOverDue(Loan* loan, Patron &patron);
public:
    void CheckOutBook(Patron* pat, Book* book);
    void CheckInBook(Patron* pat, Book* book, Loan* loan);
    void ListOverdue();
    void ListAllBookFor(Patron* pat, Books* books);
    void RecheckBook(int patronID);
//    void ReportLost(int patronID);
};
#endif /* Loans_h */
