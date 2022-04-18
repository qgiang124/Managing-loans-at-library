//
//  Books.h
//  HW3
//
//  Created by Giang Tran on 4/4/22.
//

#ifndef Books_h
#define Books_h

#include "Book.h"
#include <list>

class Books {
private:
    int count;
    list<Book> listBook;
    
public:
    void AddBook(Book currBook);
    void EditBook(int bookID);
    void DeleteBook(int bookID);
    int  SearchBook(int bookID);
    void PrintAllBook();
    void PrintBook();
};

#endif /* Books_h */
