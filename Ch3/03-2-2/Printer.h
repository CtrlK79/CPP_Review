#ifndef __PRINTER_H__
#define __PRINTER_H__

class Printer
{
private:
    char str[30];
public:
    void ShowString();
    void SetString(const char *string);
};
#endif