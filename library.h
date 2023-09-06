/*Selina Nguyen_HW1
*Header file
the prototypes of Library class functions 
(must support at least the functions
shown in main above) 
*/
#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>

class Library{

    private:
        static const int MAX = 100;
        std::string name;
        std::string bookList[MAX];
        int findBook (const std::string& name) const;

    public:
        Library();
        ~Library();
        int numberOfBooks = 0;
        bool AddBook(const std::string &name);
            //allows you to add a book title to the array
            //cannot add the same book twice
        bool RemoveBook(const std::string &name);
            //allows you to remove a book
            //take last ind entry and replace in the empty spot
        void ListAllBooks() const;
            //list books inside the array
        bool IsInLibrary(const std::string &name) const;
            //checks if book is in lib (t/f val)
        bool isFull() const;
        friend std::ostream &operator<<(std::ostream &out, const Library &lib);
};

#endif //Library
