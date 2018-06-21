#include <iostream>
using namespace std;
int add(const int , const int );
float add(const float , const float );
int main(){
    int n;
    cin >> n;
    while(n--){
        float f1, f2;
        int a, b;
        cin >> f1 >> f2 >> a >> b;
        cout << add(f1, f2) << "\n" << add(a, b) << "\n";
    }
    return 0;
}

int add(const int a, const int b){
    cout << "int add(const int, const int)\n";
    return a + b;
}

float add(const float a, const float b) {
    cout << "float add(const float, const float)\n";
    return a + b;
}