#ifndef __CALCULATOR_H_
#define __CALCULATOR_H_

class Calculator
{
private:
    int add;
    int min;
    int mul;
    int div;
public:
    void Init();
    void ShowOpCount();
    double Add(const double n1, const double n2);
    double Min(const double n1, const double n2);
    double Mul(const double n1, const double n2);
    double Div(const double n1, const double n2);
};

#endif