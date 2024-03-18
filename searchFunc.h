#include <cstring>
#include "structs.h"

typedef int (*ptrFuncSearch)(Book*, int, char*);

int searchByName(Book* arr, int index, char* value)
{
    return strcmp(value, arr[index].name);
}

int searchByAuthor(Book* arr, int index, char* value)
{
    return strcmp(value, arr[index].author);
}

ptrFuncSearch ptrSearchByName = searchByName;
ptrFuncSearch ptrSearchByAuthor = searchByAuthor;

int search(Book* arr, int sizeArr, char* value, ptrFuncSearch ptrSearchByValue)
{

    int left = 0;
    int right = sizeArr - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        int resultCmp = ptrSearchByValue(arr, middle, value);
        if (resultCmp == 0)
        {
            return middle;
        }
        else if (resultCmp > 0)
        {
            left = middle+1;
        }
        else if (resultCmp < 0)
        {
            right = middle - 1;
        }
    }

    return -1;
}

