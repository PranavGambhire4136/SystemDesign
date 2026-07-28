#include <iostream>
using namespace std;

class Singleton {
private:

    static Singleton* isObject;

    Singleton() {
        cout<<"Object is created"<<endl;
    }

public:
    static Singleton* CreateInstance() {
        if (isObject == nullptr) {
            isObject = new Singleton();
        }

        return isObject;
    }
};

Singleton* Singleton::isObject = nullptr;

int main() {
    Singleton *obj1 = Singleton::CreateInstance();
    Singleton *obj2 = Singleton::CreateInstance();


    
    cout<<"IsSame => "<<(obj1 == obj2)<<endl;
}