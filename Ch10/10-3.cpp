#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::istream;
using std::ostream;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    friend ostream& operator<<(ostream&, Point&);
    friend istream& operator>>(istream&, Point&);
};
ostream& operator<<(ostream& os, Point& ref)
{
    os<<"["<<ref.xpos<<", "<<ref.ypos<<"]"<<endl;
    return os;
}
istream& operator>>(istream& is, Point& ref)
{
    is>>ref.xpos>>ref.ypos;
    return is;
}

int main(void)
{
    Point pos1;
    cout<<"x, y 좌표 순으로 입력: ";
    cin>>pos1;
    cout<<pos1;
    
    Point pos2;
    cout<<"x, y 좌표 순으로 입력: ";
    cin>>pos2;
    cout<<pos2;
    
    return 0;
}