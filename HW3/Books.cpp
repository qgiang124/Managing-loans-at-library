//
//  Books.cpp
//  HW3
//
//  Created by Giang Tran on 4/22/22.
//

#include "Books.h"
#include <fstream>

void Books::AddBook(Book currBook) {
    listBook.push_back(currBook);
    IncCount();
}

void Books::EditBook(int bookID) {
    int choice;
    int bookPos = NULL;
    Book* currBook;
    string newAthor;
    string newTitle;
    string newISBNNum;
    int newLibID;
    double newCost;
    string newCurrStatus;
    
    bookPos = SearchBook(bookID);
    currBook = &listBook[bookPos];
    
    if (bookPos == -1) {
        cout << "The book is not found! Please try again." << endl;
    }
    else {
        cout << "What do you want to update? \n";
        cout << "1. Author \n2. Title \n3. ISBN number \n4. Library ID \n5. Cost \n6. Current status \n";
        cin  >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the new author: ";
                getline(cin >> ws, newAthor);
                currBook->SetAuthor(newAthor);
                break;
            case 2:
                cout << "Enter the new title: ";
                getline(cin >> ws, newTitle);
                currBook->SetTitle(newTitle);
                break;
            case 3:
                cout << "Enter the new ISBN number: ";
                cin >> newISBNNum;
                currBook->SetISBNNum(newISBNNum);
                break;
            case 4:
                cout << "Enter the new library ID: ";
                cin  >> newLibID;
                currBook->SetLibraryID(newLibID);
                break;
            case 5:
                cout << "Enter the new cost: ";
                cin  >> newCost;
                currBook->SetCost(newCost);
                break;
            case 6:
                cout << "Enter the new current status: ";
                getline(cin >> ws, newCurrStatus);
                currBook->SetCurrStatus(newCurrStatus);
                break;
        }
        
        cout << "Updated!\n";
    }
}

int Books::GetCount() {
    return count;
}

void Books::IncCount() {
    count++;
}

void Books::DecCount() {
    count--;
}

void Books::LoadBook() {
    Book currBook;
    ifstream inFS;
    int numBook;
    string author;
    string title;
    string ISBNNum;
    int libID;
    double cost;
    string currStatus;
    
    inFS.open("books.dat");
    if (!inFS.is_open()) {
        cout << "Could not open file books.dat" << endl;
        exit(EXIT_FAILURE);
    }
    
    //read the number of book from the first line in books.dat
    inFS >> numBook; inFS.ignore();
    
    //read the information of books from books.dat
    for (int i = 0; i < numBook; i++) {
        getline(inFS, author, ',');
        getline(inFS, title, ',');
        getline(inFS, ISBNNum, ',');
        inFS >> cost; inFS.ignore(256, ',');
        inFS >> libID; inFS.ignore(256, ',');
        inFS >> currStatus; inFS.ignore();
        
        currBook.SetAuthor(author);
        currBook.SetTitle(title);
        currBook.SetISBNNum(ISBNNum);
        currBook.SetCost(cost);
        currBook.SetLibraryID(libID);
        currBook.SetCurrStatus(currStatus);
        
        listBook.push_back(currBook);
        count++;
    }
    inFS.close();
}

void Books::DeleteBook(int bookID) {
    unsigned int bookPos; //position of the book in listBook
    bookPos = SearchBook(bookID);
    
    if (bookPos == -1) {
        cout << "The book is not found! Please try again." << endl;
    }
    else {
        listBook.erase(listBook.begin() + bookPos);
        cout << "The book is deleted!\n";
    }
    DecCount();
}

int Books::SearchBook(int bookID) {
    unsigned int pos = 0; //the posititon of the needed-to-look book
    vector<Book>::iterator iter;
    for (iter = listBook.begin(); iter != listBook.end(); iter++) {
        if ((*iter).GetLibraryID() == bookID) {
            return pos;
        }
        pos++;
    }
    return -1;
}

void Books::PrintAllBook() {
    vector<Book>::iterator iter;
    for (iter = listBook.begin(); iter != listBook.end(); iter++) {
        (*iter).PrintBook();
    }
}

void Books::PrintABook(int bookID) {
    unsigned int bookPos;
    
    bookPos = SearchBook(bookID);
    
    listBook[bookPos].PrintBook();
}


