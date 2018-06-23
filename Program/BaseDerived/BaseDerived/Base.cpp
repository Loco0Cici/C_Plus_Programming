#include <iostream>
using namespace std;
class Base {
public:
	Base() { 
		cout << "Base()\n";
	}
	virtual ~Base() {
		cout << "~Base()" << endl;
	}
};

class Derived : public Base {
public:
	Derived() { 
		cout << "Derived()\n"; 
	}
	~Derived() {
		cout << "~Derived()" << endl;
	}
};

int main() {
	Base *p = new Derived;
	delete p;
	return 0;
}