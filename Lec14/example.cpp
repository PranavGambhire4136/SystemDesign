#include <iostream>
using namespace std;


class C {
public:
    string met1() {
        return "met1 of C";
    }
};

class B {
    C c;
public:

    string met1() {
        return c.met1() + "met1 of B";
    }
};

class A {
    B b;
public:

    string met1() {
        return b.met1() + "met1 of A";
    }
};

int main() {
    A* a = new A();
    cout<<a -> met1();
}