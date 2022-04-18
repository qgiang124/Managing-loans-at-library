//
//  Patrons.h
//  HW3
//
//  Created by Giang Tran on 4/4/22.
//

#ifndef Patrons_h
#define Patrons_h

#include "Patron.h"
#include <list>

class Patrons {
private:
    list<Patron> listPatron;
    int count;
public:
    void AddPatron(Patron currPatron);
    void EditPatron(int patronID);
    void DeletePatron(int patronID);
    void SearchPatron(int patronID);
    double PayFines(int patronID);
    void PrintAllPatrons();
    void PrintPatron();
};

#endif /* Patrons_h */
