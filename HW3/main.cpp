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
using namespace std;
    
void TestBookClass() {
    Book my_book;
    Book my_2_book("giang", "my_diary", 39848392, "ieisic", 394.3, "taken");
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

int main(int argc, const char * argv[]) {
    // insert code here...
//    TestBookClass();
    TestPatronClass();
    return 0;
}
