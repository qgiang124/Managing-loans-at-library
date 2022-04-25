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
    
    currLoan->SetDueDate(GetDueTime());
    
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
}

void Loans::CheckInBook(Patron* pat, Book* book) {
    
}

string Loans::GetDueTime() {
    time_t now = time(0);
    time_t dueDate = now + CHECK_OUT_PERIOD;
    // convert now to string form
    
    char* dt = ctime(&dueDate);

    return dt;
}
