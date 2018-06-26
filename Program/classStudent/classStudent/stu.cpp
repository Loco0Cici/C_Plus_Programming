#include<stdio.h>
#include<string.h>
class Person {
	char *name;
	char gender;
	int day, month, year;
public:
	//default constructor
	Person() :name(NULL), year(1900), month(1), day(1) {  //initilization list

	}
	~Person() {  //destrcutor
		delete[] name;
		printf("~Person()\n");
	}
	//constructor with parameters
	Person(const char *n, char g, int y, int m, int d) :name(NULL), gender(g), year(y), month(m), day(d) {
		if (n != NULL)
		{
			//allocate necessary memory space for name
			name = new char[strlen(n) + 1];
			//copy characters from n to name
			strcpy(name, n);
		}
	}
	//copy constructor
	//;-valye reference,const Type &can be binded to all type of value
	Person(const Person& r) :name(NULL), gender(r.gender), year(r.year), month(r.month), day(r.day) {
		if (r.name != NULL) {
			name = new char[strlen(r.name) + 1];
			strcpy(name, r.name);
		}
	}

	void setName(const char*a) {
		//first delete memory space allocated to name
		//allocate new space for name
		//then copy from a to name
		delete[] name;
		name = NULL;
		if (a != NULL) {
			name = new char[strlen(a) + 1];
			strcpy(name, a);
		}
	}
	void setGender(const char g) {
		gender = g;
	}
	void setBirthday(const int y, const int m, const int d) {
		year = y;
		month = m;
		day = d;
	}
	void Print() const {
		printf("name:%s\n", name);
		printf("gender:%c\n", gender);
		printf("Birthday:%d-%.2d-%.2d\n", year, month, day);
	}
};
int main() {
	char name[100];
	int year, month, day;
	char gender;
	scanf("%s", name);
	scanf("%d %d %d", &year, &month, &day);
	scanf(" %c", &gender);
	Person p(name, gender, year, month, day);
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

