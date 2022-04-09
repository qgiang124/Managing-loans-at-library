//
//  Loans.h
//  HW3
//
//  Created by Giang Tran on 4/4/22.
//

#ifndef Loans_h
#define Loans_h

#include "Patron.h"
#include <vector>
using namespace std;

class Patrons {
private:
    vector<Patron> patronList;
    int count;
public:
    void AddPatron();
};

#endif /* Loans_h */
