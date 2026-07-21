#include <iostream>
using namespace std;

class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() {};
};

class NormalFly : public Flyable {
    void fly() {
        cout<<"Normal Fly"<<endl;
    }
};

class NoFly : public Flyable {
    void fly() {
        cout<<"Can't Fly"<<endl;
    }
};



class Walkable {
public:
    virtual void walk() = 0;
    virtual ~Walkable() {};
};

class NoramlWalk : public Walkable {
public:
    void walk() {
        cout<<"Normal Walk"<<endl;
    }
};

class NoWalk : public Walkable {
public:
    void walk() {
        cout<<"Can't Walk"<<endl;
    }
};



class Talkable {
public:
    virtual void talk() = 0;
    virtual ~Talkable() {};
};

class NormalTalk : public Talkable {
public:
    void talk() {
        cout<<"Normal Talk"<<endl;
    }
};

class NoTalk : public Talkable {
public:
    void talk() {
        cout<<"Can't Talk"<<endl;
    }
};


class Robot {
public:
    Talkable* talkBehaviour;
    Walkable* walkBehaviour;
    Flyable* flyBehaviour;

    Robot(Talkable* talk, Walkable* walk, Flyable* fly) {
        this -> talkBehaviour = talk;
        this -> walkBehaviour = walk;
        this -> flyBehaviour = fly;
    }

    void talk() {
        talkBehaviour -> talk();
    }

    void walk() {
        walkBehaviour -> walk();
    }

    void fly() {
        flyBehaviour -> fly();
    }

    virtual void Projection() = 0;
};

class CompanionRobot : public Robot {
public: 
    CompanionRobot(Walkable* w, Talkable* t, Flyable* f) : Robot(t, w, f) {};

    void Projection() {
        cout<<"Friendly Robot"<<endl;
    }
};

int main() {
    Robot* robot = new CompanionRobot(
        new NoramlWalk(),
        new NormalTalk(),
        new NoFly()
    );

    robot ->walk();
    robot -> talk();
    robot -> fly();
}