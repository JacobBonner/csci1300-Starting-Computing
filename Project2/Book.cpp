#include <iostream>
#include "Book.h"

Book :: Book() // default constructor
{
    title = "";
    author = "";
}

Book :: Book(string bookTitle,string authorName) // parametrized constructor
{
    title = bookTitle;
    author = authorName;
}

string Book :: getTitle()
{
    return title;
}

void Book :: setTitle(string s)
{
    title = s;
}

string Book :: getAuthor()
{
    return author;
}

void Book :: setAuthor(string auth)
{
    author = auth;
}