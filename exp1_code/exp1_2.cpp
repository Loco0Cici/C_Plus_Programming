#include <stdio.h>
#include <string.h>
class Person{
    char *name;
    char gender;
    int year, month, day;
public:
    Person() : name(NULL), year(1900), month(1), day(1){ 
        printf("Person()\n");
    }   
    ~Person() {
        printf("~Person()\n");
        delete [] name;
    }
    Person(const char *str, char g, int y, int m, int d) : name(NULL),
       gender(g), year(y), month(m), day(d) {
        printf("Person(const char*, char, int, int, int)\n");
        if(str == NULL)
            return;
        size_t len = strlen(str);
        name = new char [len + 1];
        strcpy(name, str);   
    }
    Person(const Person& other) : name(NULL), gender(other.gender), 
        year(other.year), 
        month(other.month), day(other.day){
        printf("Person(const Person&)\n");  
        if(other.name == NULL)
           return;
        size_t len = strlen(other.name);
        name = new char [len + 1];
        strcpy(name, other.name);  
    }
     
    void setGender(const char g) {
        gender = g;
    }
     
    void setBirthday(const int y, const int m, const int d){
        year = y;
        month = m;
        day = d;
    }
 
    void setName(const char* str) {
        if(name)
            delete [] name;
        name = NULL;
        if(str == NULL)
           return;
        size_t len = strlen(str);
        name = new char [len + 1];
        strcpy(name, str);
    }
     
    void Print() const{
        printf("name:%s\n", name);
        printf("gender:%c\n", gender);
        printf("Birthday:%d-%.2d-%.2d\n", year, month, day);
    }
};
int main(){
   char name[100];
   int year, month, day;
   char gender;
   scanf("%s", name);
   scanf("%d %d %d", &year, &month, &day);
   scanf(" %c", &gender);
 
   Person p(name, gender, year ,month, day);
   p.Print();
   Person s(p);
   s.Print();
   s.setName("Mark");
   s.setGender('F');
   s.Print();
   p.Print();
   Person *r = new Person(s);
   r->Print();
   delete r;   
   return 0;
}