//
//  Loans.cpp
//  HW3
//
//  Created by Giang Tran on 4/23/22.
//

#include "Loans.h"

using namespace std;

void Loans::CheckOutBook(Patron* pat, Book* book) {
    Loan* currLoan = new Loan;
    int patID, bookID;
    
    currLoan->SetLoanID(ID);
    
    cout << "Enter the patron ID: ";
    cin  >> patID; cin.ignore();
    currLoan->SetPatronID(patID);
    
    cout << "Enter the book ID: ";
    cin >> bookID; cin.ignore();
    currLoan->SetBookID(bookID);
    
//    time_t dueDate = GetDueTime();
//    char* dt = ctime(&dueDate);
//    currLoan->SetDueDate(dt);
    
    //take the current time and hence set due date
    time_t now = time(0);
    currLoan->SetDueDate(now + CHECK_OUT_PERIOD);
    
    //check if the patron is eligible to check out
    if ((pat->GetNumBooksOut() < 6) && (pat->GetFineBalance() <= 0)){
        pat->SetNumBooksOut(pat->GetNumBooksOut() + 1);
        
        ID++;
    }
    else {
        cout << "This patron has checked out more than 6 books or has overdue books.";
    }
    
    //check if the book is eligible to check out
    if (book->GetStatus() == "IN") {
        book->SetCurrStatus("OUT");
        
        listLoan.push_back(*currLoan);
        count++;
        
        cout << "Successfully checked out!" << endl;
    }
    else {
        cout << "This book is either checked out or lost.";
    }
    pat->PrintPatron();
    book->PrintBook();
    cout << "Due date: " << currLoan->GetDueDate() << endl;
}

void Loans::CheckInBook(Patron* pat, Book* book, Loan* loan) {
    unsigned int posLoan;
    
    for (unsigned int i = 0; i < count; i++) {
        if ((listLoan.at(i).GetPatronID() == pat->GetPatID()) && (listLoan.at(i).GetBookID() == book->GetLibraryID())) {
            posLoan = i;
        }
    }
    
    double amountPay;
    CheckOverDue(loan, *pat);
    //check if the patron is able to checked in
    if ((pat->GetNumBooksOut() > 0) && (pat->GetFineBalance() <= 0)) {
        pat->SetNumBooksOut(pat->GetNumBooksOut() - 1);
    }
    else if ((pat->GetNumBooksOut() > 0) && (pat->GetFineBalance() >= 0)) {
        cout << "Patron owes: $" << pat->GetFineBalance();
        cout << "Patron needs to pay dues before making a new book loan.\n";
        cout << "Enter the amount paid today: ";
        cin  >> amountPay;
        
        pat->PayFine(amountPay);
    }
    else {
        cout << "This patron has no book checked out.\n";
    }
    
    //check if the book is eligible to checked in
    if (book->GetStatus() == "OUT") {
        book->SetCurrStatus("IN");
        
        cout << "Successfully checked in!\n";
        //delete loan
        listLoan.erase(listLoan.begin() + posLoan);
        count--;
    }
    else {
        cout << "This book is either lost or already checked in.\n";
        //failed to check in so the number of book out remained
        pat->SetNumBooksOut(pat->GetNumBooksOut() + 1);
    }
}

void Loans::ListOverdue() {
    //TODO:check exist in execute menu in main
    
    vector<Loan>::iterator iter;
    for (iter = listLoan.begin(); iter != listLoan.end(); iter++) {
        (*iter).PrintLoan();
    }
}

void Loans::CheckOverDue(Loan* loan, Patron &patron){
    time_t now = time(0);
    time_t dueDate = loan->GetDueDate();
    
    double sec = difftime(now, dueDate); //seconds difference between 2 dates
    if (sec > 0) {
        int days = static_cast<int>(sec / (60 * 60 * 24));
        patron.AddFine(days * FINE_RATE);
    }
    else {
        cout << "No book overdued." << endl;
    }
}

void Loans::ListAllBookFor(Patron* pat, Books* books){
    for (int i = 0; i < count; i++) {
        if (listLoan.at(i).GetPatronID() == pat->GetPatID()) {
            if (books->SearchBook(listLoan.at(i).GetBookID() != -1)) {
             books->PrintABook(listLoan.at(i).GetBookID());
            }
        }
    }
}


