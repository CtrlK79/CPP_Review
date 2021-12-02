#include <iostream>

using std::cout;
using std::endl;

class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle(const int width, const int height) : width(width), height(height) {}
    void ShowAreaInfo() const {cout<<"면적: "<<this->width * this->height<<endl;}
};

class Square : public Rectangle
{
public:
    Square(const int side) : Rectangle(side, side) {}
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}