#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Person{
protected:
    string name;
    char gender;
    int year;
    int month;
    int day;
    bool legalBirthday(const int y, const int m, const int d) const {
        if(y < 0 || m < 0 || m > 12 || d < 0 || d > 31)
            return false;
        int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(m == 2) {
            if( y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
                if( d <= 28)
                    return true;
                else
                    return false;
            }
            else {
                if( d <= 29)
                    return true;
                else
                    return false;
            }
        }
        if(d <= a[m - 1])
            return true;
        else
            return false;
    }
public:
    Person() : name(""), gender('U'), year(1900), month(1), day(1){
        printf("Person()\n");
    }
    Person(const string& str, char g, int y, int m, int d) : name(str), gender(g) {
        printf("Person(const string&, char, int, int, int)\n");
        if(legalBirthday(y, m, d)){
            year = y, month = m, day = d;
        }
    }
    Person(const Person& other) : name(other.name), gender(other.gender), year(other.year), month(other.month), day(other.day){
        printf("Person(const Person&)\n");
    }
    ~Person(){
        printf("~Person()\n");
    }
    void setGender(char g) { gender = g;}
    void setBirthday(int y, int m, int d) {
        if(legalBirthday(y, m, d)){
            year = y, month = m, day = d;
        }
    }
    void setName(const char *str){
        name = str;
    }
    void printProperty() const {
        cout << "Name:" << name << "\n";
        cout << "Gender:" << gender << "\n";
        printf("Birthday:%d-%.2d-%.2d\n", year, month, day);
    }
};

class National_Person : public Person {
protected:
    string Nationality;
public:
    National_Person() : Nationality("N/A") {
        printf("National_Person()\n");
    }
    National_Person(const string& _name, const string& national, char g, int y, int m, int d) : Person(_name, g, y, m, d), Nationality(national) {
        printf("National_Person(const string&, const string&, char, int, int, int)\n");
    }
    void setNationality(const string& nat ){
        Nationality = nat;
    }
    void printNationality() const {
        cout << "Nationality:" << Nationality << "\n";
    }
    void printProperty() const {
        Person::printProperty();
        printNationality();
    }
    ~National_Person() {
        printf("~National_Person()\n");
    }
};

class Chinese : public National_Person {
public:
    Chinese() : National_Person () {
        printf("Chinese()\n");
        setNationality("CHN");
    }
    Chinese(const string& _name, char g, int y, int m, int d) : National_Person(_name, "CHN", g, y, m, d) {
        printf("Chinese(const string&, char, int, int, int)\n");
    }
    ~Chinese() {
        printf("~Chinese()\n");
    }
};

int main(){
    Chinese chnDmm("丁濛",'M', 1982, 5, 3);
    chnDmm.printProperty();
    return 0 ;
}