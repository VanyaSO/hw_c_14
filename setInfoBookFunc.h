#include <iostream>
#include <cstring>
using namespace std;

#include "structs.h"

typedef void (*ptrFuncSet)(Book&, char*);
typedef void (*arrPtrFuncSet)(Book&, char*);

void setName(Book& book, char* value) {
    if (book.name != nullptr)
        delete[] book.name;

    int realSize = strlen(value);
    book.name = new char[realSize+1];
    strncpy(book.name, value, realSize+1);
}

void setAuthor(Book& book, char* value) {
    if (book.author != nullptr)
        delete[] book.author;

    int realSize = strlen(value);
    book.author = new char[realSize+1];
    strncpy(book.author, value, realSize+1);
}

void setPublHouse(Book& book, char* value) {
    if (book.publishingHouse != nullptr)
        delete[] book.publishingHouse;

    int realSize = strlen(value);
    book.publishingHouse = new char[realSize+1];
    strncpy(book.publishingHouse, value, realSize+1);
}

void setGenre(Book& book, char* value) {
    if (book.genre != nullptr)
        delete[] book.genre;

    int realSize = strlen(value);
    book.genre = new char[realSize+1];
    strncpy(book.genre, value, realSize+1);
}

arrPtrFuncSet funcPointers[4] = {setName, setAuthor, setPublHouse, setGenre};

