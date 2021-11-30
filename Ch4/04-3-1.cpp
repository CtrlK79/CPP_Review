#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::sqrt;
using std::pow;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) : xpos(x), ypos(y){}
    void ShowPointInfo() const {cout<<"["<<xpos<<', '<<ypos<<"]"<<endl;}
    int GetX() const {return xpos;}
    int GetY() const {return ypos;}
};

class Circle
{
private:
    Point cen;
    int rad;
public:
    Circle(int x, int y, int r) : cen(x, y), rad(r){}
    void ShowCircleInfo() const
    {
        cout<<"radius: "<<rad<<endl;
        cen.ShowPointInfo();
    }
    Point GetCenter() const {return cen;}
    int GetRadius() const {return rad;}
};

class Ring
{
private:
    Circle inc;
    Circle otc;

public:
    Ring(int ix, int iy, int irad, int ox, int oy, int orad) : inc(ix, iy, irad), otc(ox, oy, orad){}
    void ShowRingInfo()
    {
        cout<<"Inner Circle Info..."<<endl;
        inc.ShowCircleInfo();
        cout<<"Outer Circle Info..."<<endl;
        otc.ShowCircleInfo();
    }
};