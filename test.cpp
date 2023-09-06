//file is used to test the functions in the main program file
#include "library.h"
#include <iostream>
using namespace std;

bool removeEmpty (const std::string &name, Library &libs){ //checks to see if books are being removed from an empty library
    if(libs.numberOfBooks == 0){
        cout << "Library is empty, books cannot be removed" << endl;
        return false;
    }
    bool result = libs.RemoveBook(name);
    cout<<"Yes, this book can be removed"<<endl;
    return result;
}

bool addFull (const std::string &name, Library &libs){ //checks if a library is already full and will not allow books to be added
    if(libs.numberOfBooks == 100){
        cout << "Library is full, books cannot be added" << endl;
        return false;
    }
    bool result = libs.AddBook(name);
    cout<<"Yes, there is space for this book"<<endl;
    return result;
}

int main(){

    Library libs;

    //default strings
    string inLib = "Is this book in the library?: ";

    //libs.adding Books to the lib
    libs.AddBook("Fundamentals of C++");
    libs.AddBook("Red Riding Hood");
    libs.AddBook("Ulysses");
    libs.AddBook("Don Quixote");
    libs.AddBook("In Search of Lost Time");
    libs.AddBook ("The Odyssey");

    //remove books
    cout<<"Removing Books: "<<endl;
    libs.RemoveBook("Chem");
    libs.RemoveBook("Titanic");

    //adding a duplicate
    cout<< "Can this book be added?: "<<endl;
    libs.AddBook("Ulysses");
    libs.AddBook("In Search of Lost Time");

    //checking if book is in library
    cout <<inLib<<endl;
    libs.IsInLibrary("Chem");
    libs.IsInLibrary("Red Riding Hood");

    //add book to full library
    cout<<"Is there space to add this?: "<<endl;
    addFull("Goldilocks and the Three Bears", libs);

    //remove book from empty library
    cout<<"Can this book be taken out?: "<<endl;
    removeEmpty("Red Riding Hood", libs);

    //list books
    libs.ListAllBooks();
}


