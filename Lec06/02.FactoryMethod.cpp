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


class BasicWheatBurger : public Burger {
public:
    void prepare() {
        cout<<"Basic Wheat Burger Prepared"<<endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() {
        cout<<"Standard Wheat Burger Prepared"<<endl;
    }
};

class PremimumWheatBurger : public Burger {
public:
    void prepare() {
        cout<<"Premimum Wheat Burger Prepared"<<endl;
    }
};

class BurgerFactory {
public:
    virtual Burger* CreateBurger(string type) = 0;
};


class SinghBurger : public BurgerFactory {
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


class KingBurger : public BurgerFactory {
public: 
    Burger* CreateBurger(string type) {
        if (type == "Basic") {
            return new BasicWheatBurger();
        } else if (type == "Standard") {
            return new StandardWheatBurger();
        } else if (type == "Premimum") {
            return new PremimumWheatBurger();
        } 
        else {
            cout << "Invaid type burger";
            return nullptr;
        }
    }
};

int main() {
    BurgerFactory* singhBurger = new SinghBurger();
    BurgerFactory* kingBurger = new KingBurger();
    
    string type = "Basic";
    Burger* singhBasic = singhBurger -> CreateBurger(type);
    singhBasic -> prepare();

    Burger* kingBasic = kingBurger -> CreateBurger(type);
    kingBasic -> prepare();

    type = "Standard";
    Burger* singhStandard = singhBurger -> CreateBurger(type);
    singhStandard -> prepare();

    Burger* kingStandard = kingBurger -> CreateBurger(type);
    kingStandard -> prepare();

    type = "Premimum";
    Burger* singhPremimum = singhBurger -> CreateBurger(type);
    singhPremimum -> prepare();

    Burger* kingPremimum = kingBurger -> CreateBurger(type);
    kingPremimum -> prepare();
}