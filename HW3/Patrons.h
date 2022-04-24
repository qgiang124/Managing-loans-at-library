//
//  Patrons.h
//  HW3
//
//  Created by Giang Tran on 4/4/22.
//

#ifndef Patrons_h
#define Patrons_h

#include "Patron.h"
#include <vector>

class Patrons {
private:
    vector<Patron> listPatron;
    int count;
public:
    void AddPatron(Patron currPatron);
    void DeletePatron(int patronID);
    void EditPatron(int patronID);
    void DecCount();
    void IncCount();
    int  GetCount();
    int SearchPatron(int patronID);
    double PayFines(int patronID);
    void PrintAllPatrons();
    void PrintPatron();
};

#endif /* Patrons_h */
