//
//  Loans.h
//  HW3
//
//  Created by Giang Tran on 4/4/22.
//

#ifndef Loans_h
#define Loans_h

#include "Loan.h"
#include <list>

class Loans {
private:
    int count;
    list<Loan> listLoan;
public:
    void CheckOutBook(int patronID);
    void CheckInBook(int patronID);
    void ListOverdue(int patronID);
    void ListAllBookFor(int patronID);
    void RecheckBook(int patronID);
    void ReportLost(int patronID);
};
#endif /* Loans_h */
