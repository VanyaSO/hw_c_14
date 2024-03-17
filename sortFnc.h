#include <cstring>
#include "structs.h"

void sortByName(Book*& arr, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0)
            {
                Book book = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = book;
            }
        }
    }
}

