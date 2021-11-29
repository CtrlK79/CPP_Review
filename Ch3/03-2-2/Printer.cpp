#include <iostream>
#include <cstring>
#include "Printer.h"
using std::cout;
using std::endl;
using std::strcpy;

void Printer::ShowString()
{
    cout<<str<<endl;
}

void Printer::SetString(const char *string)
{
    strcpy(str, string);
}
