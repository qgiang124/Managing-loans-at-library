//
//  Loans.h
//  HW3
//
//  Created by Giang Tran on 4/4/22.
//

#ifndef Loans_h
#define Loans_h

#include "Loan.h"
#include <vector>

class Loans {
private:
    int count;
    vector<Loan> listLoan;
public:
    void CheckOutBook();
    void CheckInBook();
    void ListOverdue();
    void ListAllBookFor(int patronID);
    void RecheckBook(int patronID);
    void ReportLost(int patronID);
};
#endif /* Loans_h */
