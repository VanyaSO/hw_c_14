const int MAX_SIZE_STR = 100;

void getString(char*& ptrStr, int size)
{

    // создаем новую строку
    char* newStr = new char[size];
    std::cin.getline(newStr, size-1);
    cin.ignore(INT_MAX, '\n');

    if (ptrStr != nullptr)
        delete[] ptrStr;

    int realSize = strlen(newStr);
    ptrStr = new char[realSize+1];
    strncpy(ptrStr, newStr, realSize+1);

    delete[] newStr;
}

