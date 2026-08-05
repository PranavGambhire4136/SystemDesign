#include <iostream>
#include <vector>
using namespace std;


class ICommand {
public:
    virtual void execute() const = 0;
    virtual void undo() const = 0;
    virtual ~ICommand(){}
};

class RemoteControl {
private:
    static const int numButton = 4;
    ICommand* button[numButton];
    bool isPresed[numButton];

public:
    RemoteControl() {
        for (int i=0; i<numButton; i++) {
            button[i] = nullptr;
            isPresed[i] = false;
        }
    }

    void setCommand(ICommand* command, int i) {
        button[i] = command;
    }

    ~RemoteControl() {
        for (int i=0; i<numButton; i++) {
            if (button[i] != nullptr) {
                delete button[i];
                isPresed[i] = false;
            }
        }
    }

    void pressButton(int i) {
        if (i >=0 && i<numButton && button[i] != nullptr) {
            if (isPresed[i]) {
                button[i] -> undo();
            } else {
                button[i] -> execute();
            }
            isPresed[i] = !isPresed[i];
        }
    }
};

class Fan {
public:
    void on() {
        cout<<"Fan is on"<<endl;
    }

    void off() {
        cout <<"Fan is off"<<endl;
    }
};

class FanCommand : public ICommand {
private:
    Fan* f;

public:
    FanCommand(Fan* f) {
        this -> f = f;
    } 

    void execute() const override {
        f -> on();
    }

    void undo() const override {
        f -> off();
    }
};


class Light {
public:
    void on() {
        cout<<"Light is on"<<endl;
    }

    void off() {
        cout <<"Light is off"<<endl;
    }
};

class LightCommand : public ICommand {
private:
    Light* l;

public:
    LightCommand(Light* l) {
        this -> l = l;
    } 

    void execute() const override {
        l -> on();
    }

    void undo() const override {
        l -> off();
    }
};

int main() {
    RemoteControl* remote = new RemoteControl();

    Light* light1 = new Light();
    Light* light2 = new Light();
    Fan* fan = new Fan();

    LightCommand* lightC1 = new LightCommand(light1);
    LightCommand* lightC2 = new LightCommand(light2);
    FanCommand* FanC = new FanCommand(fan);

    remote -> setCommand(lightC1, 0);
    remote -> setCommand(lightC2, 1);
    remote -> setCommand(FanC, 2);

    remote -> pressButton(0);
    remote -> pressButton(2);
    remote -> pressButton(0);
    remote -> pressButton(2);
}