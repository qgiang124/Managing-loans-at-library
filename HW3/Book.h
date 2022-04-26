/*
* CSCE 1040 Homework 3
* Section: 002
* Name: Giang Tran
* UNT Email: giangtran2@my.unt.edu
* Date submitted: 04/25/2022
 
* File name: Book.h
* Description:  The header file represents accessors and mutators of book's elements such as author, title, isbn number, library ID, cost and status
*/

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
    string ISBNNum;
    int    libID;
    double cost;
    string currStatus;
    
public:
    Book();
    Book(string author, string title, string ISBNNum, int libID, double cost, string currStatus);
    void SetAuthor(string authToSet);
    void SetTitle(string titToSet);
    void SetISBNNum(string numToSet);
    void SetLibraryID(int IDToSet);
    void SetCost(double costToSet);
    void SetCurrStatus(string statusToSet);
    string GetAuthor();
    string GetTitle();
    string    GetISBNNum();
    int GetLibraryID();
    double GetCost();
    string GetStatus();
    void   PrintBook();
};

#endif /* Book_h */
