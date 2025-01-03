#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Book{
    public:
    string title;
    string author;
    Book(string title, string author){
        this->title = title;
        this->author = author;
    }
};

class BookManager{
    vector<Book> Books;
    public:
    void addBook(string title, string author){
        Books.push_back(Book(title, author));
    }
    void displayAllBooks(){
        for (vector<Book>::iterator iter = Books.begin(); iter != Books.end(); iter++){
            cout << "title: " << (*iter).title << " author: " << (*iter).author << endl;
        }
    }
    void searchByTitle(string title){
        bool isExist = false;
        for (vector<Book>::iterator iter = Books.begin(); iter != Books.end(); iter++){
            if ((*iter).title == title){
                isExist = true;
                cout << "The book is Searched";
                cout << "title: " << (*iter).title << " author: " << (*iter).author << endl;
            }
            if(!isExist)
                cout << "Can not find that name book!";
        }
    }
    void searchByAuthor(string author){
        bool isExist = false;
        for(vector<Book>::iterator iter = Books.begin(); iter != Books.end(); iter++){
            if ((*iter).author == author){
                isExist = true;
                cout << "The author is Searched";
                break;
            }
        }
        if(isExist)
            for(vector<Book>::iterator iter = Books.begin(); iter != Books.end(); iter++){
                if ((*iter).author == author){
                    cout << "title: " << (*iter).title << " author: " << (*iter).author << endl;
                }
            }
        else
            cout << "Can not find that author!" << endl;
    }

};

int main(){

}
