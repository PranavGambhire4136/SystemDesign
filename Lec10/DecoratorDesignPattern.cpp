#include <iostream>
using namespace std;

class ICharacter {
public:
    virtual string getAbility() const = 0;
    ~ICharacter() {};
};

class IDecorator : public ICharacter {
protected:
    ICharacter* character;
public:
    IDecorator(ICharacter* c) {
        character = c;
    }
};

class Mario : public ICharacter {
public:
    string getAbility() const override {
        return "Mario";
    }
};

class HeightUPDec : public IDecorator {
public:
    HeightUPDec(ICharacter* c) : IDecorator(c) {}
    string getAbility() const override {
        return character->getAbility() + " with heightUP";
    }
};

class GunPowerDec : public IDecorator {
public:
    GunPowerDec(ICharacter* c) : IDecorator(c) {}

    string getAbility() const override {
        return character -> getAbility() + " with Gun Power";
    }
};

class StarPowerDec : public IDecorator {
public:
    StarPowerDec(ICharacter* c) : IDecorator(c) {}

    string getAbility() const override {
        return character -> getAbility() + " with Star Power (Limited Time)";
    }
};

int main() {
    ICharacter* mario = new Mario();

    cout<<mario -> getAbility()<<endl;

    mario = new HeightUPDec(mario);
    cout<<mario -> getAbility()<<endl;

    mario = new GunPowerDec(mario);
    cout<<mario -> getAbility()<<endl;

    ICharacter* tempMario = new StarPowerDec(mario);

    cout<<tempMario -> getAbility()<<endl;
    delete tempMario;

    cout<<mario -> getAbility()<<endl;
}