#include <iostream>

using std::cout;
using std::endl;


template <typename T>
void SwapData(T& obj1, T& obj2)
{
    T temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
};

int main(void)
{
    Point pos1(10, 20);
    Point pos2(20, 30);
    SwapData<Point>(pos1, pos2);
    pos1.ShowPosition();
    pos2.ShowPosition();

    return 0;
}