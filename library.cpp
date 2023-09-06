//the implementation of Library class functions
#include "library.h"
#include <iostream>
using namespace std;

Library::Library(){}
Library::~Library(){}

bool Library::AddBook(const std::string &name){ //adds a book to the library
    if (numberOfBooks == MAX){ //check if the library is at full capacity
        cout << "Library is full" <<endl;
        return false; 
    }
    if (numberOfBooks == 0){ //checks if there any books in the library
        bookList[0] = name;
        cout <<name + " added to Library"<<endl;
        numberOfBooks++;
        return true;
    }
    for (int i = 0; i < numberOfBooks; i++){ //checks if there are duplicates
        if (bookList[i] == name){
            cout<< name + " already exists" <<endl;
            return false; 
        }   
    }
    bookList[numberOfBooks] = name; //adds book if conditions are met
    numberOfBooks++;
    cout <<name + " added to Library"<<endl;
    return true;
}
int Library::findBook(const std::string &name)const{ //locates index of book title in library
    for (int i = 0; i < numberOfBooks; i++){
        if (bookList[i]== name){
            return i;
        }
    }
    return -1;
}

bool Library::RemoveBook(const std::string &name){ //removes book from library
    if (numberOfBooks == 0){ //checks if there are no books to remove
        cout<< "No books to remove"<< endl;
        return false;
    }
    int index = findBook(name);
    if (index == -1){ //checks if book exists in library
        cout << name + " does not exist"<<endl;
        return false; 
    }
    for (int i = index; i < numberOfBooks-1; i++){ //takes book out of library and updates library
        bookList[i] = bookList[i+1];
    }
    numberOfBooks--;
    return true;
}

bool Library::isFull() const {
    if(numberOfBooks == MAX){
        return true;
    }
    return false;
}


void Library::ListAllBooks()const{ //prints book titles in library
    cout<< "Books in Library: " <<endl;
    for (int i = 0; i < numberOfBooks; i++){
        cout << bookList[i] <<endl;
    }
}

bool Library::IsInLibrary(const std::string &name) const{ //checks if book is in library
    int index = findBook(name);
    if (index != -1){
        cout<< name + " is in the library"<<endl;
        return true;
    }
    cout<< name + " is not in the library"<<endl;
    return false;
}
