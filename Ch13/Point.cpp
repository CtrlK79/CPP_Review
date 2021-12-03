#include "Point.h"

Point::Point(int x, int y) : xpos(x), ypos(y) {}

ostream& operator<<(ostream& os, const Point& ref)
{
    os<<'['<<ref.xpos<<", "<<ref.ypos<<']'<<endl;
    return os;
}