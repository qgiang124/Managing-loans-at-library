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
    int count = 0;
    int FoundPatron(int patronID); //return true if patron found in list
public:
    void AddPatron(Patron currPatron);
    void DeletePatron(int patronID);
    void EditPatron(int patronID);
    void DecCount();
    void IncCount();
    int  GetCount();
    Patron*  SearchPatron(int patronID);
    void LoadPatron();
    void PayFines(int patronID);
    void PrintAllPatrons();
    void PrintAPatron(int patronID);
    void StorePatron();
};

#endif /* Patrons_h */
