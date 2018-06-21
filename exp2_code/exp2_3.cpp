#include <stdio.h>
#include <iostream>
using namespace std;

class String{
private:
    char *str;
    size_t length;
public:
    String() : str(NULL), length(0) { }
    ~String() {
        delete [] str;
    }
    String(const char *s) : str(NULL), length(0){
        if(s == NULL)
            return;
        length = strlen(s);
        str = new char [length + 1];
        strcpy(str, s);
    }
    String(const String& other) : str(NULL), length(0){
        if(other.isNull())
            return;
        length = other.length;
        str = new char [length + 1];
        strcpy(str, other.str);
    }
    bool isNull() const {
        if(str == NULL)
            return true;
        else
            return false;
    }
    String& operator = (const String &other)  {
        if(this == &other)
            return *this;
        delete [] str;
        str = NULL;
        length = 0;
        if(other.isNull())
            return *this;
        length = other.length;
        str = new char [length + 1];
        strcpy(str, other.str);
        return *this;
    }
    String operator + (const String&other) const  {
        if(other.isNull())
            return *this;
        if(isNull())
            return other;
        char *temp = new char [length + other.length + 1];
        strcpy(temp, str);
        strcpy(temp + length, other.str);
        String Str;
        Str.length = length + other.length;
        Str.str = temp;
        return Str;
    }
    String& operator+= (const String& other){
        if(other.isNull())
            return *this;
        if(isNull())
            return (*this) = other;
        char *temp = new char [length + other.length + 1];
        strcpy(temp, str);
        strcpy(temp + length, other.str);
        delete [] str;
        str = temp;
        length = length + other.length;
        return *this;
    }
    String& operator << (const String &other) {
        return (*this) += other;
    }
    String& append(const String &other) {
        return (*this) += other;
    }
    char& operator[](int idx) {
        return str[idx];
    }
    
    friend std::ostream& operator << (std::ostream& out, const String& s);
};
std::ostream& operator << (std::ostream& out, const String& s) {
    if(s.isNull())
        return out;
    return out << s.str;
}

int main(){
    String a("This is "), b(a);
    String c;
    cout << "a:" << a << "\n" << "b:" << b << "\n" << "c:" << c << "\n";
    c = "a test.";
    cout << "c:" << c << "\n";
    a.append(c);
    cout << "a:" << a << "\n";
    {
        String a("Hello"), b;
        a += " World";
        b  << (a + b);
        cout << "b:" << b << "\n";
        String c;
        c = b + "!";
        cout << "c:" << c << "\n";
    }
    a[0] = 't';
    cout << "a:" << a << "\n";
    return 0;
}