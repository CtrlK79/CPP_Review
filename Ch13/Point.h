#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0);
    friend ostream& operator<<(ostream& os, const Point& ref);
};
#endif