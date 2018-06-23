#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class Base {
private:
	int base;
public:
	Base() {
		cout << "Base()" << endl;
		base = 0;
	}
	Base(int n) {
		cout << "Base(int n)" << endl;
		base = n;
	}
	~Base() {
		cout << "~Base()" << endl;
	}
	Base(const Base &other) {
		cout << "Base(const Base &other)" << endl;
		base = other.base;
	}
	void override_fun() {
		cout << "»ùÀà°ævoid override_fun()" << endl; 
	}
	void base_fun() {
		cout << "void base_fun()" << endl; 
	}
};


class Derive :public Base {
public:
	Derive() {
		cout << "Derive()" << endl;
		derive = 0;
	}
	Derive(int n) {
		cout << "Derive(int n)" << endl;
		derive = n;
	}
	~Derive() {
		cout << "~Derive(int n)" << endl;
	}
	Derive(const Derive &tmp_Derive) {
		cout << "Derive(const Derive &tmp_Derive)" << endl;
		derive = tmp_Derive.derive;
	}
	void override_fun() { 
		cout << "ÅÉÉú°ævoid override_fun()" << endl; 
	}
	void derive_fun() { 
		cout << "void derive_fun()" << endl; 
	}
private:
	int derive;
};

int main()
{
	Base *class_base = new Base(5);;
	Derive *class_derive = new Derive();
	class_base->override_fun();
	class_derive->override_fun();
	class_base = class_derive;
	class_base->base_fun();
	class_base->override_fun();
	//class_derive = class_base; 
}