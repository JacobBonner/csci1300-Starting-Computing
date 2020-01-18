# include <iostream>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book
{
    public:
        Book(); // default constructor
        Book(string,string); // parametrized constructor
        string getTitle();
        void setTitle(string);
        string getAuthor();
        void setAuthor(string);
    
    private:
        string title;
        string author;
};

#endif