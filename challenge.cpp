#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef unordered_map<string, int> Stock;

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
    Book* findBookByTitle(string title){
        
    }
    Book* findBookByAuthor(string author){

    }
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
    Book* getBookByTitle(string title){

    }

    Book* getBookByAuthor(string author){

    }
};

class BorrowManager{
    unordered_map<string, int> stock;
    public:
    void initializeStock(Book book, int quantity=3){
        stock.insert(make_pair(book.title, quantity));
    }
    void borrowBook(string title){
        if (stock.find(title) != stock.end()) {
            int quantityOfBook = stock[title];
            if(quantityOfBook > 0){
                stock[title] -= 1;
                cout << "Borrow success!";
            }
            else{
                cout << "Out of stock!";
            }
        } else {
            cout << "Book not found!" << endl;
        }
            cout << " title: "  << title << endl;
    }
    void returnBook(string title){
        if (stock.find(title) != stock.end() && stock[title] < 3) {
            stock[title] += 1;
            cout << "Book is returned successfully!";
        }
        else {
            cout << "The book is not ours!";
        }
        cout << " title: "  << title << endl;

    }
    void displayStock(){
        for (Stock::iterator iter = stock.begin(); iter != stock.end(); iter ++){
            cout << "Title: " << iter->first << " stock: " << iter->second << endl;
        }
    }
};

int main(){
    BookManager bkm = BookManager(); 
    BorrowManager bwm = BorrowManager();

    // Add books
    bkm.addBook("book1","A");
    bkm.addBook("book2","A");
    bkm.addBook("book3","B");
    bkm.addBook("book4","C");
    bkm.addBook("book5","C");
    bkm.addBook("book6","D");
    bkm.addBook("book7","D");
    bkm.addBook("book8","D");

    //Init book stock
    bwm.initializeStock(Book("book1","A"));
    bwm.initializeStock(Book("book2","A"));
    bwm.initializeStock(Book("book3","B"));
    bwm.initializeStock(Book("book4","C"));
    bwm.initializeStock(Book("book5","C"));
    bwm.initializeStock(Book("book6","D"));
    bwm.initializeStock(Book("book7","D"));
    bwm.initializeStock(Book("book8","D"));

    bwm.displayStock();
    
    // borrow 3 book3
    bwm.borrowBook("book3");
    bwm.borrowBook("book3");
    bwm.borrowBook("book3");

    // borrow book3 again(out of stack)
    bwm.borrowBook("book3");

    // return 3 book3
    bwm.returnBook("book3");
    bwm.returnBook("book3");
    bwm.returnBook("book3");

    // return over 3 stock
    bwm.returnBook("book3");

}
