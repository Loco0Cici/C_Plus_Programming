#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Person {
private:
	string name;
	char gender;
	int year,month,day;
	bool legalBirthday(const int y, const int m, const int d) const {
		if (y < 0 || m < 0 || m > 12 || d < 0 || d > 31)
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
	Person() : name(""), gender('U'), year(1900), month(1), day(1) {
		cout<<"Person()"<<endl;
	}
	Person(const string& s, char g, int y, int m, int d) : name(s), gender(g) {
		cout << "Person(const string&, char, int, int, int)" << endl;
		if (legalBirthday(y, m, d)) {
			year = y;
			month = m;
			day = d;
		}
	}
	Person(const Person& other) : name(other.name), gender(other.gender), year(other.year), month(other.month), day(other.day) {
		cout << "Person(const Person&)" << endl;
	}
	~Person() {
		cout << "~Person()" << endl;
	}
	void setGender(char g) { gender = g; }
	void setBirthday(int y, int m, int d) {
		if (legalBirthday(y, m, d)) {
			year = y;
			month = m;
			day = d;
		}
	}
	void setName(const char *str) {
		name = str;
	}
	void print() const {
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
		cout << "National_Person()" << endl;
	}
	National_Person(const string& n, const string& national, char g, int y, int m, int d) : Person(n, g, y, m, d), Nationality(national) {
		cout << "National_Person(const string&, const string&, char, int, int, int)" << endl;
	}
	~National_Person() {
		cout << "~National_Person()" << endl;
	}
	void setNationality(const string& nat) {
		Nationality = nat;
	}
	void printNationality() const {
		cout << "Nationality:" << Nationality << endl;
	}
	void printProperty() const {
		Person::print();
		printNationality();
	}
};

class Chinese : public National_Person {
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

int main() {
	Chinese chnDmm("ÀîÊæç÷", 'F', 1999, 4, 8);
	chnDmm.printProperty();
	return 0;
}