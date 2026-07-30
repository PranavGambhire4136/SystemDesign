#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
using namespace std;

class MenuItem {
private: 
    string code;
    string name;
    double price;

public:
    MenuItem(string code, string name, double price) {
        this ->code = code;
        this -> name = name;
        this -> price = price;
    }

    void setCode(string code) {
        this -> code = code;
    }
    
    string getCode() {
        return code;
    }

    void setName(string name) {
        this -> name = name;
    }

    string getName(){
        return name;
    }

    void setPrice(double price) {
        this -> price = price;
    }

    double getPrice() const{
        return price;
    }
};


#endif