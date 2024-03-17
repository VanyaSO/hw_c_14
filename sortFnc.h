#include <cstring>
#include "structs.h"

typedef int (*ptrFuncSorting)(Book*&, int);
typedef int (*arrPtrFuncSorting)(Book*&, int);


int sortByName(Book*& arr, int index)
{
    return strcmp(arr[index].name, arr[index + 1].name);
}

int sortByAuthor(Book*& arr, int index)
{
    return strcmp(arr[index].author, arr[index + 1].author);
}

int sortByPublHouse(Book*& arr, int index)
{
    return strcmp(arr[index].publishingHouse, arr[index + 1].publishingHouse);
}

arrPtrFuncSorting funcSorting[3] = {sortByName, sortByAuthor, sortByPublHouse};


void sorting(Book*& arr, int size, ptrFuncSorting func)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (func(arr, j) > 0)
            {
                Book book = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = book;
            }
        }
    }
}

