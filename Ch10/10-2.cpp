#include <iostream>

using std::cout;
using std::endl;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    void ShowPosition() const {cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;}
    Point& operator++() {xpos++; ypos++; return *this;}
    Point& operator-() {xpos*=-1; ypos*=-1; return *this;}
    Point& operator~() {xpos=~xpos; ypos=~ypos; return *this;}
    friend Point& operator--(Point& ref);
};
Point& operator--(Point& ref)
{
    ref.xpos--;
    ref.ypos--;
    return ref;
}

int main(void)
{
    Point pos1(2, 3);
    Point pos2(3, 4);

    Point pos3 = ~pos1;
    pos3.ShowPosition();
    Point pos4 = -pos2;
    pos4.ShowPosition();

    return 0;
}