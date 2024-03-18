#include <iostream>
using namespace std;

void printOneBook(Book* arr, int index)
{
    cout << "Название: " << arr[index].name << endl ;
    cout << "Автор: " << arr[index].author << endl;
    cout << "Издатель: " << arr[index].publishingHouse << endl;
    cout << "Жанр: " <<arr[index].genre << endl;
    cout << endl;
}

void printBooks(Book* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        printOneBook(arr, i);
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
