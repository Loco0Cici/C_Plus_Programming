#include <iostream>
using namespace std;
class Complex{
        double real;
        double imagine;
public:
        Complex(double r = 0., double i = 0.) : real(r), imagine(i) { }
        Complex(const Complex& other) : real(other.real), imagine(other.imagine){ }
        Complex operator + (const Complex& other) const {
                return Complex(real + other.real, imagine + other.imagine);
            }
        Complex operator - (const Complex& other) const {
                return Complex(real - other.real, imagine - other.imagine);
            }
        Complex& operator = (const Complex& other){
                if(this == &other)
                        return *this;
                real = other.real;
                imagine = other.imagine;
                return *this;
            }
         
        friend ostream & operator << (ostream& out, const Complex& c);
        friend Complex operator *(const Complex& o1, const Complex& o2);
};
 
ostream & operator << (ostream& out, const Complex& c){
        return out << c.real << " + " << c.imagine << " i\n";
}
 
Complex operator *(const Complex& o1, const Complex& o2) {
        return Complex(o1.real * o2.real - o1.imagine * o2.imagine, o1.real * o2.imagine + o1.imagine * o2.real);
}
int main(){
        Complex c1(4.234234, -27.6), c2(3.5, -4.7);
        Complex c3, c4;
        c3 = c2 + c1;
        c4 = c3 * c1;
        c2 = c4 - c1;
        cout  << c1  << c2  << c3  << c4  << c1 - c4 ;
        return 0;
}
 
</iostream>