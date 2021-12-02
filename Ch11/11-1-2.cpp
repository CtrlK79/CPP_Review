#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

class Book
{
private:
    char* title;
    char* isbn;
    int price;
public:
    Book(const char* title, const char* isbn, const int price)
    : price(price)
    {
        this->title = new char[strlen(title)+1]; strcpy(this->title, title);
        this->isbn = new char[strlen(isbn)+1]; strcpy(this->isbn, isbn);
    }
    Book(const Book& copy)
    : price(copy.price)
    {
        title = new char[strlen(copy.title)+1]; strcpy(title, copy.title);
        isbn = new char[strlen(copy.isbn)+1]; strcpy(isbn, copy.isbn);
    }
    Book& operator=(const Book& ref)
    {
        delete []title; delete []isbn;
        title = new char[strlen(ref.title)+1]; strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn)+1]; strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
    }
    void ShowBookInfo() const
    {
        cout<<"제목: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"가격: "<<price<<endl;
    }
};

class EBook : public Book
{
private:
    char* DRMKey;
public:
    EBook(const char* title, const char* isbn, const int price, const char* DRMKey)
    : Book(title, isbn, price) {this->DRMKey = new char[strlen(DRMKey)+1]; strcpy(this->DRMKey, DRMKey);}
    EBook(const EBook& copy)
    : Book(copy) // Ah...
    {
        DRMKey = new char[strlen(copy.DRMKey)+1]; strcpy(DRMKey, copy.DRMKey);
    }
    EBook& operator=(const EBook& ref)
    {
        Book::operator=(ref);
        delete []DRMKey;
        DRMKey = new char[strlen(ref.DRMKey)+1]; strcpy(DRMKey, ref.DRMKey);
        return *this;
    }
    void ShowEBookInfo() const
    {
        ShowBookInfo();
        cout<<"인증키: "<<DRMKey<<endl;
    }
};

int main(void)
{
    EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    EBook ebook2 = ebook1;
    EBook ebook3("아주좋은 C++ ebook", "555-12345-891-1", 12000, "fdx9w0i8kij");
    ebook3 = ebook1;
    ebook3.ShowEBookInfo();

    return 0;
}