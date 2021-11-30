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
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<', '<<ypos<<"]"<<endl;
    }
    int GetX() const
    {
        return xpos;
    }
    int GetY() const
    {
        return ypos;
    }
};

class Circle
{
private:
    Point cen;
    int rad;

public:
    void Init(int x, int y, int r)
    {
        if(r<=0)
        {
            cout<<"입력된 반지름이 0 이하입니다."<<endl;
            return;
        }
        cen.Init(x, y);
        rad = r;
    }
    void ShowCircleInfo() const
    {
        cout<<"radius: "<<rad<<endl;
        cen.ShowPointInfo();
    }
    Point GetCenter() const
    {
        return cen;
    }
    int GetRadius() const
    {
        return rad;
    }
};

class Ring
{
private:
    Circle inc;
    Circle otc;

public:
    void Init(int ix, int iy, int irad, int ox, int oy, int orad)
    {
        if(orad<irad || (sqrt(pow(ix-ox, 2)+pow(iy-oy, 2))+irad < orad))
        {
            cout<<"두 원의 관계가 링이 되지 않습니다."<<endl;
            return;
        }
        inc.Init(ix, iy, irad);
        otc.Init(ox, oy, orad);
    }
    void ShowRingInfo()
    {
        cout<<"Inner Circle Info..."<<endl;
        inc.ShowCircleInfo();
        cout<<"Outer Circle Info..."<<endl;
        otc.ShowCircleInfo();
    }
};