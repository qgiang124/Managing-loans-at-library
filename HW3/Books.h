//
//  Books.h
//  HW3
//
//  Created by Giang Tran on 4/4/22.
//

#ifndef Books_h
#define Books_h

#include "Book.h"
#include <vector>

class Books {
private:
    int count =  0;
    vector<Book> listBook;
public:
    void AddBook(Book currBook);
    void DeleteBook(int bookID);
    void EditBook(int bookID);
    int GetCount();
    void IncCount();
    void DecCount();
    void LoadBook();
    void PrintAllBook();
    void PrintBook(int bookID);
    int  SearchBook(int bookID);
};

#endif /* Books_h */
