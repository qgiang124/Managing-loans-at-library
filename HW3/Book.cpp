//
//  Book.cpp
//  HW3
//
//  Created by Giang Tran on 4/8/22.
//

#include "Book.h"

Book::Book(){
    author     = "none";
    title      = "none";
    ISBNNum    = "none";
    libID      = 0;
    cost       = 0;
    currStatus = "none";
}

Book::Book(string author, string title, string ISBNNum, int libID, double cost, string currStatus) {
    this->author = author;
    this->title  = title;
    this->libID  = libID;
    this->cost   = cost;
    this->currStatus = currStatus;
}

void Book::SetAuthor(string authToSet){
    author = authToSet;
}

void Book::SetTitle(string titToSet) {
    title = titToSet;
}

void Book::SetISBNNum(string numToSet) {
    ISBNNum = numToSet;
}

void Book::SetLibraryID(int IDToSet) {
    libID = IDToSet;
}

void Book::SetCost(double costToSet) {
    cost = costToSet;
}

void Book::SetCurrStatus(string statusToSet){
    currStatus = statusToSet;
}

string Book::GetAuthor(){
    return author;
}

string Book::GetTitle() {
    return title;
}

string Book::GetISBNNum() {
    return ISBNNum;
}

int Book::GetLibraryID() {
    return libID;
}

double Book::GetCost() {
    return cost;
}

string Book::GetStatus() {
    return currStatus;
}

void Book::PrintBook() {
    cout << "----------BOOK DETAILS--------------\n";
    cout << left << setw(20) << "Title: " << title << endl;
    cout << left << setw(20) << "Author: " << author << endl;
    cout << left << setw(20) << "ISBNNum: " << ISBNNum << endl;
    cout << left << setw(20) << "Library ID number: " << libID << endl;
    cout << left << setw(20) << "Cost: " << "$" << cost << endl;
    cout << left << setw(20) << "Status: " << currStatus << endl;
}
