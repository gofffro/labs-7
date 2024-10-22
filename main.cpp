#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string author;
    string title;
    int year;
    int countBook;
    double price;
};



vector<Book> getBooks(string path) {
    Book book;
    vector<Book> books;
    fstream file(path);
    if (file.is_open()) {
        while (file >> book.author >> book.title >> book.year >> book.countBook >> book.price) {
            replace(book.title.begin(), book.title.end(), '.', ' ');
            books.push_back(book);
        }
    }
    file.close();
    return books;
}

void displayBooksAuthor (vector<Book> books, string author) {
    double totalPrice = 0;
    cout << "Книги авторства - " << author << endl;
    for (int vectorIndex = 0; vectorIndex < books.size(); ++vectorIndex) {
        if (books[vectorIndex].author == author) {
            cout << "Название: " << books[vectorIndex].title << endl;
            cout << "Год выпуска: " << books[vectorIndex].year << endl;
            cout << "Количество: " << books[vectorIndex].countBook << endl;
            cout << "Цена: " << books[vectorIndex].price << endl;
            totalPrice += books[vectorIndex].price;
        }
    }
    cout << "Общая стоимость: " << totalPrice << endl;
}

void findOldestBook(vector<Book> books) {
    int olderYear = 9999;
    for (int vectorIndex = 0; vectorIndex < books.size(); ++vectorIndex) {
        if (olderYear > books[vectorIndex].year) {
            olderYear = books[vectorIndex].year;
        }
    }
    cout << "Самая старая книга в списке: " << endl;
    for (int vectorIndex = 0; vectorIndex < books.size(); ++vectorIndex) {
        if (books[vectorIndex].year == olderYear) {
            cout << "Автор: " << books[vectorIndex].author << endl;
            cout << "Название: " << books[vectorIndex].title << endl;
            cout << "Год выпуска: " << books[vectorIndex].year << endl;
            cout << "Количество: " << books[vectorIndex].countBook << endl;
            cout << "Цена: " << books[vectorIndex].price << endl;
        }
    }
}

int main() {
    string path = "books.txt";
    string author;
    vector<Book> books = getBooks(path);
    
    cout << "Введите фамилию автора(Пушкин, Чехов, Толстой): ";
    cin >> author;
    displayBooksAuthor(books, author);
    
    cout << " " << endl;
    findOldestBook(books);
}