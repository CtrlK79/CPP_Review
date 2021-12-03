#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    int len;
    char* str;
public:
    String();
    String(const char* str);
    String(const String& ref);
    ~String();

    String& operator=(const String& ref);
    String& operator+=(const String& ref);
    bool operator==(const String& ref) const;
    String operator+(const String& ref) const;
    friend ostream& operator<<(ostream& os, const String& ref);
    friend istream& operator>>(istream& is, String& ref);

};
String::String()
{
    len = 0;
    str = NULL;
}
String::String(const char* str)
{
    len = strlen(str)+1;
    this->str = new char[len]; strcpy(this->str, str);
}
String::String(const String& ref)
{
    len = ref.len;
    str = new char[len]; strcpy(str, ref.str);
}
String::~String() {if(str!=NULL) delete []str;}
String& String::operator=(const String& ref)
{
    if(str!=NULL)
        delete []str;
    len = ref.len;
    str = new char[ref.len]; strcpy(str, ref.str);
    return *this;
}
String& String::operator+=(const String& ref)
{
    //strcpy((&str[len-1]), ref.str);
    //len = len + ref.len - 1;
    //return *this;
    len+=(ref.len-1);
    char* tempstr = new char[len];
    strcpy(tempstr, str); strcat(tempstr, ref.str);

    if(str!=NULL)
        delete []str;
    str=tempstr;
    return *this;
}
bool String::operator==(const String& ref) const
{
    return strcmp(str, ref.str)? false : true;
}
String String::operator+(const String& ref) const
{
    char* tempstr = new char[len+ref.len-1];
    strcpy(tempstr, str); strcat(tempstr, ref.str);

    String temp(tempstr);
    delete []tempstr;
    return temp;
}
ostream& operator<<(ostream& os, const String& ref)
{
    os<<ref.str;
    return os;
}
istream& operator>>(istream& is, String& ref)
{
    char str[100];
    is>>str;
    ref = String(str);
    return is;
}

int main(void)
{
    String str1 = "I like ";
    String str2 = "string class";
    String str3 = str1+str2;

    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1+=str2;
    if(str1==str3)
        cout<<"동일 문자열!"<<endl;
    else
        cout<<"동일하지 않은 문자열"<<endl;
    
    string str4;
    cout<<"문자열 입력: ";
    cin>>str4;
    cout<<"입력한 문자열: "<<str4<<endl;

    return 0;
}