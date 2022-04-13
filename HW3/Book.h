//
//  Book.h
//  HW3
//
//  Created by Giang Tran on 3/28/22.
//

#ifndef Book_h
#define Book_h

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book {
private:
    string author;
    string title;
    int    ISBNNum;
    string libID;
    double cost;
    string currStatus;
    
public:
    Book();
    Book(string author, string title, int ISBNNum, string libID, double cost, string currStatus);
    void SetAuthor(string authToSet);
    void SetTitle(string titToSet);
    void SetISBNNum(int numToSet);
    void SetLibraryID(int IDToSet);
    void SetCost(double costToSet);
    void SetCurrStatus(string statusToSet);
    string GetAuthor();
    string GetTitle();
    int    GetISBNNum();
    string GetLibraryID();
    double GetCost();
    string GetStatus();
    void   PrintBook();
};

#endif /* Book_h */
