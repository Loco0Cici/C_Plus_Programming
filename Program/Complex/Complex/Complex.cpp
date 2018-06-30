#include<iostream>
using namespace std;
class Complex {
protected:
	double real;
	double imagine;
public:
	Complex() :real(0), imagine(0) {

	}
	Complex(const double a, const double b) :real(a), imagine(b) {

	}
	Complex(const Complex&other):real(other.real),imagine(other.imagine) {

	}
	Complex operator +(const Complex &add) const {
		return Complex(real + add.real, imagine + add.imagine);
	}
	Complex operator - (const Complex &minus) const {
		return Complex(real - minus.real, imagine - minus.imagine);
	}
	Complex operator =(const Complex &equal) {
		if (this == &equal) {
			return *this;
		}
		else {
			real = equal.real;
			imagine = equal.imagine;
			return *this;
		}
	}
	friend Complex operator *(const Complex &multiplication1, const Complex &multiplication2);
	friend ostream & operator <<(ostream &out, const Complex &com);
};
Complex operator *(const Complex &multiplication1, const Complex &multiplication2){
	return Complex(multiplication1.real * multiplication2.real - multiplication1.imagine * multiplication2.imagine, multiplication1.real * multiplication2.imagine + multiplication1.imagine * multiplication2.real);
}
ostream &operator <<(ostream &print, const Complex &com) {
	 print<< com.real<<"+" << com.imagine << "i" << endl;
	 return print;
}

int main() {
	Complex c1(4.234234, -27.6), c2(3.5, -4.7);
	Complex c3, c4;
	c3 = c2 + c1;
	c4 = c3 * c1;
	c2 = c4 - c1;
	cout << c1 << c2 << c3 << c4 << c1 - c4;
	return 0;
}