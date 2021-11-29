#include <iostream>
#include "Calculator.h"
using std::cout;
using std::endl;

void Calculator::Init()
{
    add = 0; min = 0; mul = 0; div = 0;
}
void Calculator::ShowOpCount()
{
    cout<<"덧셈: "<<add<<" ";
    cout<<"뺄셈: "<<min<<" ";
    cout<<"곱셈: "<<mul<<" ";
    cout<<"나눗셈: "<<div<<endl;
}
double Calculator::Add(const double n1, const double n2)
{
    add++;
    return n1+n2;
}
double Calculator::Min(const double n1, const double n2)
{
    min++;
    return n1-n2;
}
double Calculator::Mul(const double n1, const double n2)
{
    mul++;
    return n1*n2;
}
double Calculator::Div(const double n1, const double n2)
{
    div++;
    return n1/n2;
}