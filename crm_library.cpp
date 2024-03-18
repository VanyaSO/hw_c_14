#include <iostream>
#include <cstring>
using namespace std;

#include "structs.h"
#include "printFunc.h"
#include "setInfoBookFunc.h"
#include "sortFunc.h"
#include "searchFunc.h"
#include "stringFunc.h"

void deleteBooksArr(Book*& arr, int size)
{
    for (int i = 0; i < size; ++i) {
        delete[] arr[i].name;
        delete[] arr[i].author;
        delete[] arr[i].publishingHouse;
        delete[] arr[i].genre;
    }
    delete[] arr;
}

// Функция, которая инициализирует строку структуры книги, в зависимости какой указатель на какую фукнцию мы передали
void setBookInfo(Book& book, ptrFuncSet func)
{
    char* value = nullptr;
    getString(value, MAX_SIZE_STR);
    func(book, value);

    delete[] value;
}

void editBook(Book& book, arrPtrFuncSet arrFunc[])
{

    int action = 0;
    bool isPrintMenu = true;

    while(true)
    {
        if (isPrintMenu)
            printEditBookMenu();

        cin >> action;
        if (action < 0 || action > 4)
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
                cout << "Введите новое название: ";
                break;
            case 2:
                cout << "Введите нового автор: ";
                break;
            case 3:
                cout << "Введите издательство: ";
                break;
            case 4:
                cout << "Введите жанр: ";
                break;
            case 0:
                return;
        }
        cin.ignore(INT_MAX, '\n');
        setBookInfo(book, arrFunc[action-1]);
        cout << "Данные успешно обновлены!" << endl;
    }
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

Book createBook()
{
    cin.ignore(INT_MAX, '\n');

    Book book;
    cout << "Для создания книги введите" << endl;

    cout << "Название книги: ";
    setBookInfo(book, setName);

    cout << "Автор: ";
    setBookInfo(book, setAuthor);

    cout << "Издательство: ";
    setBookInfo(book, setPublHouse);

    cout << "Жанр: ";
    setBookInfo(book, setGenre);

    return book;
}

void mainMenu(Book*& booksArr, int& sizeBooksArr)
{
    int action = 0;
    int searchIndex;
    bool isPrintMenu = true;
    char* valueSearchBook = nullptr;

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
        // показваем меню
        isPrintMenu = true;

        switch (action) {
            case 1:
                addBook(booksArr, sizeBooksArr, createBook());
                cout << "Новая книга создана!" << endl;
                continue;
            case 2:
                cout << "Введите название книги которую вы хотите редактировать" << endl;
                cin.ignore(INT_MAX, '\n');
                getString(valueSearchBook, MAX_SIZE_STR);
                // сортируем массив по имени
                sorting(booksArr, sizeBooksArr, ptrSortByName);
                // ищем index книги которую пользователь хочет редактировать
                searchIndex = search(booksArr, sizeBooksArr, valueSearchBook, ptrSearchByName);
                // редактируем книгу
                editBook(booksArr[searchIndex], funcPointers);
                continue;
            case 3:
                printBooks(booksArr, sizeBooksArr);
                continue;
            case 4:
                cout << "Введите автора книги которую вы хотите найти" << endl;
                cin.ignore(INT_MAX, '\n');
                getString(valueSearchBook, MAX_SIZE_STR);
                // сортируем массив по имени
                sorting(booksArr, sizeBooksArr, ptrSortByName);
                // ищем книгу которую пользователь хочет редактировать
                searchIndex = search(booksArr, sizeBooksArr, valueSearchBook, ptrSearchByAuthor);
                // проверяем нашли ли мы книгу если да принти ее
                if (searchIndex >= 0)
                    printOneBook(booksArr, searchIndex);
                else
                    cout << "Книга не найдена" << endl;
                continue;
            case 5:
                cout << "Введите название книги которую вы хотите найти" << endl;
                cin.ignore(INT_MAX, '\n');
                getString(valueSearchBook, MAX_SIZE_STR);
                // сортируем массив по имени
                sorting(booksArr, sizeBooksArr, ptrSortByName);
                // ищем книгу которую пользователь хочет редактировать
                searchIndex = search(booksArr, sizeBooksArr, valueSearchBook, ptrSearchByName);
                // проверяем нашли ли мы книгу если да принти ее
                if (searchIndex >= 0)
                    printOneBook(booksArr, searchIndex);
                else
                    cout << "Книга не найдена" << endl;
                continue;
            case 6:
                sorting(booksArr, sizeBooksArr, ptrSortByName);
                cout << "Массив по названию успешно остартирован!" << endl;
                continue;
            case 7:
                sorting(booksArr, sizeBooksArr, ptrSortByAuthor);
                cout << "Массив по автору успешно остартирован!" << endl;
                continue;
            case 8:
                sorting(booksArr, sizeBooksArr, ptrSortByPublHouse);
                cout << "Массив по издательству успешно остартирован!" << endl;
                continue;
            case 0:
                deleteBooksArr(booksArr, sizeBooksArr);
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
    Book book7 {"Аватар", "Ольга Николаева", "Морские Горизонты", "Романтика"};
    Book book8 {"Шепот ветра", "Дмитрий Иванов", "Созвездие", "Приключения"};
    Book book9 {"Изгнанники времени", "Елена Васильева", "Страницы Времени", "Исторический роман"};
    Book book10 {"Космическая опасность", "Игорь Кузнецов", "Космический Путь", "Научная фантастика"};


    // собираем в массив
    const int sizeStaticArr = 10;
    Book staticArrBook[sizeStaticArr] = {
            book1, book2, book3, book4, book5, book6, book7, book8, book9, book10
    };

    //переписываем в динамический масив
    int sizeBooksArr = 0;
    Book* booksArr = nullptr;
    for (int i = 0; i < sizeStaticArr; ++i) {
        addBook(booksArr, sizeBooksArr, staticArrBook[i]);
    }

    mainMenu(booksArr, sizeBooksArr);

    deleteBooksArr(booksArr, sizeBooksArr);
    return 0;
}












