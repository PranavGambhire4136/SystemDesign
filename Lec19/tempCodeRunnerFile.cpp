#include <iostream>
using namespace std;

class Handler {
protected:
    Handler* next;
public:
    Handler() {
        this -> next = nullptr;
    }

    void setHandler(Handler* next) {
        this -> next = next;
    }

    virtual bool dispense(int amount) = 0;
};

class ThousandHandler : public Handler {
protected:
    int noOfNotes;
public:

    ThousandHandler(int noOfNotes) {
        this -> noOfNotes = noOfNotes;
    }

    bool dispense(int amount) override {
        int requiredNote = amount / 1000;

        if (noOfNotes > requiredNote) {
            
            int leftMoney = amount % 1000;
            
            if(next -> dispense(leftMoney)) {
                noOfNotes -= requiredNote;
                cout<<requiredNote<<" of thousand has been dispensed";
                return true;
            }
            return false;
        } else {
            return next -> dispense(amount);
        }
    }
};


class FiveHundreadHandler : public Handler {
protected:
    int noOfNotes;
public:

    FiveHundreadHandler(int noOfNotes) {
        this -> noOfNotes = noOfNotes;
    }

    bool dispense(int amount) override {
        int requiredNote = amount / 500;

        if (noOfNotes > requiredNote) {
            
            int leftMoney = amount % 500;
            
            if(next -> dispense(leftMoney)) {
                noOfNotes -= requiredNote;
                cout<<requiredNote<<" of thousand has been dispensed";
                return true;
            }
            return false;
        } else {
            return next -> dispense(amount);
        }
    }
};


class HundreadHandler : public Handler {
protected:
    int noOfNotes;
public:

    HundreadHandler(int noOfNotes) {
        this -> noOfNotes = noOfNotes;
    }

    bool dispense(int amount) override {
        int requiredNote = amount / 100;

        if (noOfNotes > requiredNote) {
            
            int leftMoney = amount % 100;
            
            if(leftMoney == 0) return true;
            return false;
        } else {
            return false;
        }
    }
};

class ProxyHandler : public Handler {
public: 
    ProxyHandler() {
        Handler* thousand = new ThousandHandler(3);
        
        Handler* fiveHundread = new FiveHundreadHandler(5);

        Handler* hundread = new HundreadHandler(2);

        this -> next = thousand;
        thousand->setHandler(fiveHundread);
        fiveHundread -> setHandler (hundread);
    }

    bool dispense(int amount) {
        next -> dispense(amount);
    }
};

int main() {
    Handler* ATM = new ProxyHandler();

    ATM -> dispense(1000);

    cout<<endl<<"Program ended";
}