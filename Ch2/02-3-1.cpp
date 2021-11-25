#include <iostream>
using std::cout;
using std::endl;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point * result = new Point;
    result->xpos = p1.xpos + p2.xpos;
    result->ypos = p1.ypos + p2.ypos;
    
    return *result;
}

int main(void)
{
    Point * p = new Point[2];
    
    p[0].xpos = 1; p[0].ypos = 1;
    p[1].xpos = 3; p[1].ypos = -3;

    Point &ref = PntAdder(p[0], p[1]);
    cout<<"("<<ref.xpos<<", "<<ref.ypos<<")"<<endl;

    return 0;
}