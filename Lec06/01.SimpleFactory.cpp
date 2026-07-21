#include <iostream>
using namespace std;

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

class BasicBurger : public Burger {
public:
    void prepare() {
        cout<<"Basic Burger Prepared"<<endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() {
        cout<<"Standard Burger Prepared"<<endl;
    }
};

class PremimumBurger : public Burger {
public:
    void prepare() {
        cout<<"Premimum Burger Prepared"<<endl;
    }
};

class BurgerFactory {
public:

    Burger* CreateBurger(string type) {
        if (type == "Basic") {
            return new BasicBurger();
        } else if (type == "Standard") {
            return new StandardBurger();
        } else if (type == "Premimum") {
            return new PremimumBurger();
        } 
        else {
            cout << "Invaid type burger";
            return nullptr;
        }
    }
};

int main() {
    string type = "Basic";

    BurgerFactory* bf = new BurgerFactory();

    Burger* B1 = bf -> CreateBurger(type);
    B1 -> prepare();

    type = "Standard";
    Burger* B2 = bf -> CreateBurger(type);
    B2 -> prepare();

    type = "Premimum";
    Burger* B3 = bf -> CreateBurger(type);
    B3 -> prepare();
}