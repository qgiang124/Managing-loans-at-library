/*
* CSCE 1040 Homework 3
* Section: 002
* Name: Giang Tran
* UNT Email: giangtran2@my.unt.edu
* Date submitted: 04/25/2022
 
* File name: main.cpp
* Description:  The programs implement library structures.
*/
 

#include <iostream>
#include "Books.h"
#include "Patrons.h"
#include "Loans.h"
#include "Book.h"
#include "Loan.h"
#include "Patron.h"

using namespace std;

void PrintMenu() {
    cout << "==================MENU CHOICE=================\n";
    cout <<  "0 - Quit\n 1 - Check out book\n 2 - Check in book\n 3 - Recheck book\n 4 - Report Lost\n 5 - List loans\n 6 - List patrons\n 7 - List books\n 8 - Add Patron\n 9 - Delete Patron\n 10 - Edit patron\n 11 - Search patron\n 12 - Add book\n 13 - Delete book\n 14 - Edit book\n 15 - Seaach book\n";
}

void ExecuteMenu(Patrons& listPat, Books& listBook, Loans& listLoan) {
    int choice;
    int patID;
    int bookID;
    int loanID;
    string namePat;
    double fineBal;
    int numBooksOut;
    string author;
    string title;
    string ISBNNum;
    int    libID;
    double cost;
    string currStatus;
    Patron* currPat;
    Book*  currBook;
    Loan* currLoan;
    
    switch (choice) {
        case 1:
            cout << "Enter the patron ID: ";
            cin  >> patID;
            cout << "Enter the book ID: ";
            cin  >> bookID;
            
            currPat = listPat.SearchPatron(patID);
            currBook = listBook.SearchBook(bookID);
            listLoan.CheckOutBook(currPat, currBook);
            break;
        case 2:
            cout << "Enter the patron ID: ";
            cin  >> patID;
            cout << "Enter the book ID: ";
            cin  >> bookID;

            currPat = listPat.SearchPatron(patID);
            currBook = listBook.SearchBook(bookID);
            listLoan.CheckInBook(currPat, currBook);
            break;
        case 3:
            listLoan.RecheckBook(currLoan);
        case 4:
            cout << "Enter the patron ID: ";
            cin  >> patID;
            cout << "Enter the book ID: ";
            cin  >> bookID;

            currPat = listPat.SearchPatron(patID);
            currBook = listBook.SearchBook(bookID);
            
            listLoan.ReportLost(currPat, currBook);
            break;
        case 5:
            listLoan.ListOverdue(); break;
        case 6:
            listPat.PrintAllPatrons(); break;
        case 7:
            listBook.PrintAllBook(); break;
        case 8:
            cout << "Enter the patron name: ";
            getline(cin >> ws, namePat);
            cout << "Enter the patron ID: ";
            cin >> patID;
            cout << "Enter the patron fine balance: ";
            cin  >> fineBal;
            cout << "Enter number of books out: ";
            cin  >> numBooksOut;
            
            currPat->SetPatID(patID);
            currPat->SetFineBal(fineBal);
            currPat->SetPatName(namePat);
            currPat->SetNumBooksOut(numBooksOut);
            
            listPat.AddPatron(*currPat);
            break;
        case 9:
            cout << "Enter the patron ID: ";
            cin  >> patID;
            listPat.DeletePatron(patID);
            break;
        case 10:
            cout << "Enter the patron ID: ";
            cin  >> patID;
            listPat.EditPatron(patID);
            break;
        case 11:
            cout << "Enter the patron ID: ";
            cin  >> patID;
            currPat = listPat.SearchPatron(patID);
            currPat->PrintPatron();
        case 12:
            cout << "Enter book's name: ";
            getline(cin >> ws, title);
            cout << "Enter book's author: ";
            getline(cin >> ws, author);
            cout << "Enter ISBN number: ";
            cin  >> ISBNNum;
            cout << "Enter library ID: ";
            cin  >> libID;
            cout << "Enter the cost: ";
            cin  >> cost;
            cout << "Enter current status (IN, OUT, LOST): ";
            cin  >> currStatus;
            
            currBook->SetTitle(title);
            currBook->SetAuthor(author);
            currBook->SetISBNNum(ISBNNum);
            currBook->SetLibraryID(libID);
            currBook->SetCost(cost);
            currBook->SetCurrStatus(currStatus);
            
            listBook.AddBook(*currBook);
            break;
        case 13:
            cout << "Enter the book ID: ";
            cin  >> bookID;
            
            listBook.DeleteBook(bookID);
            break;
        case 14:
            cout << "Enter the book ID: ";
            cin  >> bookID;
            
            listBook.EditBook(bookID);
            break;
        case 15:
            cout << "Enter the book ID: ";
            cin  >> bookID;
            
            currBook = listBook.SearchBook(bookID);
            currBook->PrintBook();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
    delete currPat;
    delete currBook;
    delete currLoan;
}

int main() {
    Patrons listPatron;
    Books listBook;
    Loans listLoan;
    int choice;
    
    listPatron.LoadPatron();
    listBook.LoadBook();
    listLoan.LoadLoan();
    
    PrintMenu();
    
    cout << "Enter your selection: ";
    cin >> choice; cin.ignore();
    while (choice != 0) {
        ExecuteMenu(listPatron, listBook, listLoan);
        PrintMenu();
        
        cout << "Enter your selection: ";
        cin >> choice; cin.ignore();
    }
    
    listPatron.StorePatron();
    listBook.StoreBook();
    listLoan.StoreLoan();
    
    return 0;
}
