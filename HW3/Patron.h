//
//  Patron.h
//  HW3
//
//  Created by Giang Tran on 3/28/22.
//

#ifndef Patron_h
#define Patron_h
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Patron{
private:
    string  name;
    int     IDNum;
    double  fineBalance;
    int     numBooksOut;
public:
    Patron();
    Patron(string name, int IDNum, double fineBalance, int numBooksOut);
    void SetPatName(string nameToSet);
    void SetPatID(int IDToSet);
    void SetFineBal(double amountToSet);
    void SetNumBooksOut(int numToSet);
    void AddFine(int amount);
    void PayFine(int amount);
    string GetPatName();
    int    GetPatID();
    double GetFineBalance();
    int    GetNumBooksOut();
    void PrintPatron();
    
};

#endif /* Patron_h */
