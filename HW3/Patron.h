//
//  Patron.h
//  HW3
//
//  Created by Giang Tran on 3/28/22.
//

#ifndef Patron_h
#define Patron_h

class Patron{
private:
    string  name;
    int     IDNum;
    double  fineBalance;
    int     numBooksOut;
public:
    void SetPatName(string nameToSet);
    void SetPatID(int IDToSet);
    void SetFineBal(doulbe amountToSet);
    void SetNumBooksOut(int numToSet);
    string GetPatName();
    int    GetPatID();
    double GetFineBalance();
    int    GetNumBooksOut();
}

#endif /* Patron_h */
