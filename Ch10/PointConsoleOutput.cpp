#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    void ShowPoint() const {cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;}
    friend ostream& operator<<(ostream&, const Point& ref);
};
ostream& operator<<(ostream& os, const Point& ref)
{
    os<<"["<<ref.xpos<<", "<<ref.ypos<<"]"<<endl;
    return os;
}

int main(void)
{
    Point pos1(1, 3);
    cout<<pos1;
    Point pos2(101, 303);
    cout<<pos2;

    return 0;
}