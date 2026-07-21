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

class GarlicBread {
public: 
    virtual void prepare() = 0;
    virtual ~GarlicBread() {};
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() {
        cout<<"Basic Garlic Bread Prepared"<<endl;
    }
};

class StandardGarlicBread : public GarlicBread {
public:
    void prepare() {
        cout<<"Standard Garlic Bread Prepared"<<endl;
    }
};

class PremimumGarlicBread : public GarlicBread {
public:
    void prepare() {
        cout<<"Premimum Garlic Bread Prepared"<<endl;
    }
};


class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() {
        cout<<"Basic Wheat Garlic Bread Prepared"<<endl;
    }
};

class StandardWheatGarlicBread : public GarlicBread {
public:
    void prepare() {
        cout<<"Standard Wheat Garlic Bread Prepared"<<endl;
    }
};

class PremimumWheatGarlicBread : public GarlicBread {
public:
    void prepare() {
        cout<<"Premimum Wheat Garlic Bread Prepared"<<endl;
    }
};


class Factory {
public:
    virtual Burger* CreateBurger(string type) = 0;
    virtual GarlicBread* CreateGarlicBread(string type) = 0;
};


class SinghBurger : public Factory {
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

    GarlicBread* CreateGarlicBread(string type) {
        if (type == "Basic") {
            return new BasicGarlicBread();
        } else if (type == "Standard") {
            return new StandardGarlicBread();
        } else if (type == "Premimum") {
            return new PremimumGarlicBread();
        } 
        else {
            cout << "Invaid type burger";
            return nullptr;
        }
    }
};


class KingBurger : public Factory {
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

    GarlicBread* CreateGarlicBread(string type) {
        if (type == "Basic") {
            return new BasicWheatGarlicBread();
        } else if (type == "Standard") {
            return new StandardWheatGarlicBread();
        } else if (type == "Premimum") {
            return new PremimumWheatGarlicBread();
        } 
        else {
            cout << "Invaid type burger";
            return nullptr;
        }
    }
};

int main() {
    Factory* factory = new KingBurger();

    string burgerType = "Standard";
    string garlicBreadType = "Basic";

    Burger* burger = factory -> CreateBurger(burgerType);
    burger -> prepare();
    GarlicBread* garlicBread = factory -> CreateGarlicBread(garlicBreadType);
    garlicBread -> prepare();
}