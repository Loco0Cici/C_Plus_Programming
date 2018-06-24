#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Person {
protected:
	string name;
	char gender;
	int year;
	int month;
	int day;
	bool legalBirthday(const int y, const int m, const int d) const {
		if (y< 0 || m < 0 || m > 12 || d < 0 || d > 31)
			return false;
		int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (m == 2) {
			if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
				if (d <= 28)
					return true;
				else
					return false;
			}
			else {
				if (d <= 29)
					return true;
				else
					return false;
			}
		}
		if (d <= a[m - 1])
			return true;
		else
			return false;
	}
public:
	Person() : name(), gender('U'), year(1900), month(1), day(1) {
		printf("Person()\n");
	}
	Person(const string&str, char g, int y, int m, int d) : name(str), gender(g) {
		printf("Person(const string&, char, int, int, int)\n");
		if (legalBirthday(y, m, d)) {
			year = y, month = m, day = d;
		}
	}
	Person(const Person& other) : name(other.name), gender(other.gender), year(other.year), month(other.month), day(other.day) {
		printf("Person(const Person&)\n");
	}
	~Person() {
		printf("~Person()\n");
	}
	void setGender(char g) {
		gender = g;
	}
	void setBirthday(int y, int m, int d) {
		if (legalBirthday(y, m, d)) {
			year = y, month = m, day = d;
		}
	}
	void setName(const char *str) {
		name = str;
	}
	void printProperty() const {
		cout << "Name:" << name << "\n";
		cout << "Gender:" << gender << "\n";
		printf("Birthday:%d-%.2d-%.2d\n", year, month, day);
	}
};

class National_Person :virtual public Person {
protected:
	string Nationality;
public:
	National_Person() : Nationality("N/A"), Person() {
		cout << "National_Person()" << endl;
	}
	National_Person(const string& n, const string& national, char g, int y, int m, int d) : Person(n, g, y, m, d), Nationality(national) {
		cout << "National_Person(const string&, const string&, char, int, int, int)" << endl;
	}
	void setNationality(const string& nat) {
		Nationality = nat;
	}
	~National_Person() {
		cout << "~National_Person()" << endl;
	}
	void printNationality() const {
		cout << "Nationality:" << Nationality << endl;
	}
	void printProperty() const {
		Person::printProperty();
		printNationality();
	}
};

class Chinese :public National_Person {
public:
	Chinese() : National_Person() {
		cout << "Chinese()" << endl;
		setNationality("CHN");
	}
	Chinese(const string& n, char g, int y, int m, int d) : National_Person(n, "CHN", g, y, m, d) {
		cout << "Chinese(const string&, char, int, int, int)" << endl;
	}
	~Chinese() {
		cout << "~Chinese()" << endl;
	}
};

class Student : virtual public Person {
protected:
	string school_name;
	string ID;
	int grade;
public:
	Student() : Person(), school_name("N/A"), ID("N/A"), grade(0) {
		cout << "Student()" << endl;
	}
	Student(const string& n, char g, int y, int m, int d, const string& sn, const string& id, int gra) : Person(n, g, y, m, d), school_name(sn), ID(id), grade(gra) {
		cout << "Student(const string&, char, int, int, int, const string&, const string&, int)" << endl;
	}
	~Student() {
		cout << "~Student()" << endl;
	}
	void setSchoolName(const string& sname) {
		school_name = sname;
	}
	void setStudentID(const string& id) {
		ID = id;
	}
	void setGrade(int g) {
		grade = g;
	}
	void printProperty() const {
		Person::printProperty();
		cout << "School Name:" << school_name << endl;
		cout << "Student ID:" << ID << endl;
		cout << "Grade:" << grade << endl;
	}
};

class Chinese_Student :public Student, public Chinese {
public:
	Chinese_Student() :Chinese(), Student() {
		cout << "Chinese_Student()" << endl;
	}
	Chinese_Student(const string& n, char g, int y, int m, int d, const string& sn, const string& sid, int _grade) : Student(n, g, y, m, d, sn, sid, _grade), Chinese(n, g, y, m, d) {
		cout << "Chinese_Student(const string&, char, int, int, int, const string&, const string&, int)" << endl;
	}
	~Chinese_Student() {
		cout << "~Chinese_Student()" << endl;
	}
	void printProperty() const {
		Chinese::printProperty();
		Student::printProperty();
	}
};
int main() {
	Chinese_Student chnStuDmm("¶¡÷", 'M', 1982, 5, 3, "ZJU", "3001112322", 2000);
	cout << "Before:\n";
	chnStuDmm.printProperty();
	chnStuDmm.setName("Gavotte");
	cout << "\nAfter:\n";
	chnStuDmm.printProperty();
	return 0;
}
