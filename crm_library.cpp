#include <iostream>
#include <cstring>
using namespace std;

#include "structs.h"
#include "sortFnc.h"



//Розробіть програму "Бібліотека". Створіть структуру "Книга" (назва, автор, видавництво, жанр). Створіть масив із 10 книг. Реалізуйте для нього такі можливості:
//Редагувати книгу;
//Друк усіх книг;
//Пошук книги за автором;
//Пошук книги за назвою;
//Сортування масиву за назвою книг;
//Сортування масиву за автором;
//Сортування масиву за видавництвом.



const int MAX_SIZE_STR = 100;

typedef void (*ptrFuncSet)(Book&, char*);
typedef void (*arrPtrFuncSet)(Book&, char*);


// для остального пока не писал
void setName(Book& book, char* value) {
    if (book.name != nullptr) {
        // это для теста
        cout << "Получаем имя setName " << book.name << endl;
//        delete[] book.name;  // когда удаляю пишет ошибки
    }

    int realSize = strlen(value);
    book.name = new char[realSize + 1];
    for (int i = 0; i < realSize; ++i) {
        book.name[i] = value[i];
    }
    book.name[realSize] = '\0';

    cout << "Присваиваем имя setName " << book.name << endl;
}

void getString(char*& ptrStr, int size)
{
    // создаем новую строку
    char* newStr = new char[size];
    std::cin.getline(newStr, size-1);
    cin.ignore(INT_MAX, '\n');

    // копируем строку на реальное количество елементов
    int realSize = strlen(newStr);
    ptrStr = new char[realSize+1];
    for (int i = 0; i < realSize; ++i) {
        ptrStr[i] = newStr[i];
    }
    ptrStr[realSize] = '\0';

    cout << "Получили в getStr " << ptrStr << endl;

    delete[] newStr;
}

// Функция, которая инициализирует строку структуры книги, в зависимости какой указатель на какую фукнцию мы передали
void setBookInfo(Book& book, ptrFuncSet func)
{
    char* value = nullptr;
    getString(value, MAX_SIZE_STR);
    func(book, value);

    delete[] value;
}

void printBooks(Book* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << "Название: " << arr[i].name << endl ;
        cout << "Автор: " << arr[i].author << endl;
        cout << "Издатель: " << arr[i].publishingHouse << endl;
        cout << "Жанр: " <<arr[i].genre << endl;
        cout << endl;
    }
}

void printEditBookMenu()
{
    cout << "Что вы хотите изменить, введите номер варианта: " << endl;
    cout << "1) Название" << endl;
    cout << "2) Автора" << endl;
    cout << "3) Издатель" << endl;
    cout << "4) Жанр" << endl;
    cout << "0) Выйти в главное меню" << endl;
}
void editBook(Book& book, arrPtrFuncSet arrFunc[])
{
    // для удобства arrFunc = [setName, setAuthor, setPublHouse, setGenre]
    printEditBookMenu();

    int action = 0;

    while (true)
    {
        cin >> action;

        if (action == 1)
        {
            cout << "Введите новое название: ";
        }
        else if (action == 2)
        {
            cout << "Введите нового автор: ";
        }
        else if (action == 3)
        {
            cout << "Введите издательство: ";
        }
        else if (action == 4)
        {
            cout << "Введите жанр: ";
        }
        else if (action == 0)
        {
            cout << "0" << endl;
            break;
        }
        else
        {
            cout << " Введите коректное значение" << endl;
            continue;
        }

        break;
    }

    setBookInfo(book, arrFunc[action-1]);
}

void addBook(Book*& arr, int& size, Book el)
{
    Book* newArr = new Book[size+1];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = el;

    delete[] arr;
    size+=1;
    arr = newArr;
}

Book createBook(arrPtrFuncSet arrFunc[])
{
    Book book;
    cout << "Для создания книги введите" << endl;

    cout << "Название книги: ";
    setBookInfo(book, arrFunc[0]);

//    cout << "Автор: ";
//    setBookInfo(book, arrFunc[1]);
//
//    cout << "Издательство: ";
//    setBookInfo(book, arrFunc[2]);
//
//    cout << "Жанр: ";
//    setBookInfo(book, arrFunc[3]);

    return book;
}

void printMainMenu()
{
    cout << "Что вы хотите сделать? Введите номер варианта: " << endl;
    cout << "1) Создать книгу" << endl;
    cout << "2) Редактировать книгу" << endl;
    cout << "3) Распечатать все книги" << endl;
    cout << "4) Поиск книги по автору" << endl;
    cout << "5) Поиск книги по названию" << endl;
    cout << "6) Сортировать массив по названию книги" << endl;
    cout << "7) Сортировать массив по автору" << endl;
    cout << "8) Сортировать массив по издательству" << endl;
    cout << "0) Завершить работу" << endl;
}

void mainMenu(Book*& booksArr, int& sizeBooksArr, arrPtrFuncSet funcPointers[])
{
    int action = 0;
    bool isPrintMenu = true;

    while(true)
    {
        if (isPrintMenu)
            printMainMenu();

        cin >> action;
        if (action < 0 || action > 8)
        {
            cout << "Введите коректное значение: " << endl;
            // скрываем меню чтобы оно не отображалось пока пользователь не введет коректное значение
            isPrintMenu = false;
            continue;
        }
        // показываем меню
        isPrintMenu = true;

        switch (action) {
            case 1:
                addBook(booksArr, sizeBooksArr, createBook(funcPointers));
                continue;
            case 2:
                // нужно отсортировать
                // найти елемент который пользователь хочет редактировать
                editBook(booksArr[0], funcPointers);
                continue;
            case 3:
                printBooks(booksArr, sizeBooksArr);
                cout << "Книги распечатаны!" << endl;
            case 4:
                //Пошук книги за автором;
                continue;
            case 5:
                //Пошук книги за назвою;
                continue;
            case 6:
                sortByName(booksArr, sizeBooksArr);
                cout << "Массив успешно остартирован!" << endl;
                continue;
            case 7:
                //Сортування масиву за автором;
                continue;
            case 8:
                //Сортування масиву за видавництвом.
                continue;
            case 0:
                exit(0);
        }
        break;
    }
}

int main()
{

    // создаем книги
    Book book1 {"Пленник времени", "Мария Иванова", "Звезда Принта", "Фантастика"};
    Book book2 {"Последнее предательство", "Александр Петров", "Литературный Мир", "Драма"};
    Book book3 {"Тайные корни", "Елена Смирнова", "Знание", "Детектив"};
    Book book4 {"Эхо молчания", "Николай Федоров", "Печать Века", "Триллер"};
    Book book5 {"Шепот живой природы", "Анна Коваленко", "Лесная Сказка", "Фэнтези"};
    Book book6 {"Мрак ночи", "Сергей Сидоров", "Тень Прошлого", "Ужасы"};
    Book book7 {"Сердце моря", "Ольга Николаева", "Морские Горизонты", "Романтика"};
    Book book8 {"Шепот ветра", "Дмитрий Иванов", "Созвездие", "Приключения"};
    Book book9 {"Изгнанники времени", "Елена Васильева", "Страницы Времени", "Исторический роман"};
    Book book10 {"Космическая опасность", "Игорь Кузнецов", "Космический Путь", "Научная фантастика"};


    // собираем в массив
    const int sizeStaticArr = 10;
    Book staticArrBook[sizeStaticArr] = {
            book1, book2, book3, book4, book5,
            book6, book7, book8, book9, book10
    };
    //переписываем в динамический масив
    int sizeBooksArr = 0;
    Book* booksArr = nullptr;
    for (int i = 0; i < sizeStaticArr; ++i) {
        addBook(booksArr, sizeBooksArr, staticArrBook[i]);
    }

    // масив указателей на функции для создания строки структуры книги
    arrPtrFuncSet funcPointers[1] = {setName}; //setAuthor, setPublHouse, setGenre};

    mainMenu(booksArr, sizeBooksArr, funcPointers);

//    cout << "Введите новое имя: " << endl;
//    setBookInfo(booksArr[0], funcPointers[0]);


    delete[] booksArr;
    return 0;
}












