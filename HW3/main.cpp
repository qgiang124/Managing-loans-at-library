//
//  main.cpp
//  HW3
//
//  Created by Giang Tran on 3/28/22.
//

#include <iostream>
#include "Books.h"
#include "Patrons.h"
#include "Loans.h"
#include "Book.h"
#include "Loan.h"
#include "Patron.h"

using namespace std;
    
void TestBookClass() {
    Book my_book;
    Book my_2_book("giang", "my_diary", "39848392", 3432 , 394.3, "taken");
    my_book.PrintBook();
    cout << "---------------------------------\n";
    my_2_book.PrintBook();
    cout << my_book.GetCost() << endl;
    cout << my_2_book.GetTitle() << endl;
    my_book.SetCost(39) ;
    cout << my_book.GetCost() << endl;
}

void TestPatronClass() {
    Patron my_patron;
    Patron my_2_patron("john", 389, 3.4, 3);
    my_patron.SetPatID(432);
    my_patron.PrintPatron();
    cout << "---------------------------" << endl;
    my_2_patron.PrintPatron();
    
}

void TestLoanClass() {
    Loan loan1;
    Loan loan2(234, 345, 34, 4363);
    loan1.SetLoanID(353);
    loan1.PrintLoan();
    cout << "-----------------" << endl;
    loan2.PrintLoan();
}

int main() {
//    TestBookClass();
//    TestPatronClass();
//    TestLoanClass();
//    Books listBook;
    Patrons listPatron;
//
//    cout << "Enter book name: " << endl;
//    listBook.LoadBook();
//    listBook.PrintAllBook();
    
//    listPatron.LoadPatron();
//    listPatron.PrintAllPatrons();
    time_t now = time(0);
//    cout << now << endl;
    time_t due=  now  + CHECK_OUT_PERIOD;
    
    cout << difftime(now, due) << endl << due;
//    listPatron.PayFines(3);
    return 0;
}
