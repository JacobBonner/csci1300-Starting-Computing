// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Project 2 - Problem # 0

# include "Book.h"
# include "User.h"
# ifndef LIBRARY_H
# define LIBRARY_H


class Library
{
    public:
        Library();
        int getSizeBook();
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        int readBooks(string); // populates books array and returns the number of books in the array
        int readRatings(string); // populates users array and returns the number of users in the array
        void printAllBooks(); // prints all books stored in books array
        int getCountReadBooks(string); // returns the number of books read by the given user
        double calcAvgRating(string); // returns the average rating of the specified book as a double
        int addUser(string); // returns different values if the user is successfully added, if it already exists, or if the array is already full
        int checkOutBook(string,string,int); // returns different values if the rating is successfully updated, if the rating is not valid, or if the title or user do not exist
        void viewRatings(string); // prints all the books a user provided ratings for
        int getRating(string,string); // returns a given user's ratings for specified book
        void getRecommendations(string); // prints the first 5 book recommendations from the most similar other user
    private:
        const static int sizeBook = 50;
        const static int sizeUser = 100;
        Book books[sizeBook];
        User users[sizeUser];
        int numBooks;
        int numUsers;
        int split(string,char,string[],int);
};

# endif