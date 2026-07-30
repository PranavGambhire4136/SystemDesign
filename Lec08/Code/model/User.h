#ifndef USER_H
#define USER_H

#include "Cart.h"

#include <iostream>
#include <string>


class User {
private:
    int id;
    string name;
    string address;
    Cart* cart;

public: 
    User(int id, string name, string address) {
        this -> id = id;
        this -> name = name;
        this -> address = address; 
        this -> cart = new Cart();
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this -> name = name;
    }

    string getAddress() {
        return address;
    }

    void setAddress(string name) {
        this -> address = address;
    }

    Cart* getCart() {
        return cart;
    }
};

#endif