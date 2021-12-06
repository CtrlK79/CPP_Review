#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

template <typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(const T x=0, const T y=0) : xpos(x), ypos(y) {}
    void ShowPosition() const {cout<<'['<<xpos<<", "<<ypos<<']'<<endl;}
};

template <typename T>
class SimpleDataWrapper
{
private:
    T mdata;
public:
    SimpleDataWrapper(const T data) : mdata(data) {}
    void ShowDataInfo(void) const
    {
        cout<<"Data: "<<mdata<<endl;
    }
};

template <>
class SimpleDataWrapper <char*>
{
private:
    char* mdata;
public:
    SimpleDataWrapper(const char* data)
    {
        mdata = new char[strlen(data)+1];
        strcpy(mdata, data);
    }
    void ShowDataInfo(void) const
    {
        cout<<"String: "<<mdata<<endl;
        cout<<"Length: "<<strlen(mdata)<<endl;
    }
    ~SimpleDataWrapper() {delete []mdata;}
};

template <>
class SimpleDataWrapper < Point<int> >
{
private:
    Point<int> mdata;
public:
    SimpleDataWrapper(const int x, const int y) : mdata(x, y) {}
    void ShowDataInfo(void) const
    {
        mdata.ShowPosition();
    }
};

int main(void)
{
    SimpleDataWrapper<int> iwrap(170);
    iwrap.ShowDataInfo();
    SimpleDataWrapper<char*> swrap("Class Template Specialization");
    swrap.ShowDataInfo();
    SimpleDataWrapper< Point<int> > poswrap(3, 7);
    poswrap.ShowDataInfo();

    return 0;
}