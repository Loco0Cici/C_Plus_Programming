#include <iostream>
#include <string>
using namespace std;
class Figure {
public:
    const static double pi;
    virtual double getArea() const {
        return 0.;
    }
    virtual void print() const{
        cout << "Figure:" << getArea();
    }
};
const double Figure::pi = 3.1415927;
class Rectangle : public Figure{
    double height;
    double width;
public:
    Rectangle(double h = 0., double w = 0.) : height(h), width(w) {
        
    }
    double getArea() const{
        return width * height;
    }
    virtual void print() const{
        cout << "Rectangle:" << getArea();
    }
};
class Circle : public Figure {
    double radius;
public:
    Circle (double r = 0.) : radius(r){
        
    }
    double getArea() const {
        return radius * radius * pi;
    }
    virtual void print() const{
        cout << "Circle:" << getArea();
    }
};
class Square : public Rectangle {
public:
    Square(double l = 0.) : Rectangle(l, l){
        
    }
    virtual void print() const{
        cout << "Square:" << getArea();
    }
};
bool compare(const Figure *o1, Figure *o2){
    return o1->getArea() < o2->getArea();
}
int main(){
    Rectangle rect(3. , 5.);
    Circle circle(8. / Figure::pi);
    Square square(4.);
    
    Figure *pList [] = {&rect, &circle, &square};
    Figure *min = pList[0];
    for(int i = 1; i < 3; ++i){
        if(compare(pList[i], min)){
            pList[i]->print();
            printf(" < ");
            min->print();
            printf("\n");
            min = pList[i];
        }
        else{
            min->print();
            printf(" < ");
            pList[i]->print();
            printf("\n");
        }
    }
    printf("Minimum:\n");
    min->print();
    printf("\n");
    return 0;
}