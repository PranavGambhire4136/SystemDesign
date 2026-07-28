#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout<<"The object of Class A is created"<<endl;
    }
};

int main() {
    A* a1 = new A();
    A* a2 = new A();


    cout<<"IsSame => "<<(a1 == a2)<<endl;

    return 0;
}