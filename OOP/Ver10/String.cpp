/*
 * File Name : String.cpp
 * Author : Jaewoo Kim
 * File Ver : 0.9
 */

#include "String.h"

String::String()
: len(0), str(NULL) {}

String::String(const char* s)
: len(strlen(s)+1) {str = new char[len]; strcpy(str, s);}

String::String(const String& s)
: len(s.len) {str = new char[len]; strcpy(str, s.str);}

String::~String() {if(str!=NULL) delete []str;}

String& String::operator=(const String& s)
{
    if(str!=NULL)
        delete []str;
    len = s.len;
    str = new char[len]; strcpy(str, s.str);
    return *this;
}

String& String::operator+=(const String& s)
{
    len+=(s.len-1);
    char* tempstr = new char[len];
    strcpy(tempstr, str);
    strcat(tempstr, s.str);

    if(str!=NULL)
        delete []str;
    str=tempstr;
    return *this;
}

bool String::operator==(const String& s) const
{
    return strcmp(str, s.str)? false : true;
}

String String::operator+(const String& s) const
{
    String temp;
    temp = *this; temp+=s;
    return temp;
}

ostream& operator<<(ostream& os, const String& s)
{
    os<<s.str;
    return os;
}

istream& operator>>(istream& is, String& s)
{
    char str[100];
    is>>str;
    s = String(str);
    return is;   
}