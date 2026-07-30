#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "MenuItem.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Restaurant {
private: 
    static int nextResId;
    int id;
    string name;
    string location;
    vector<MenuItem> menu;

public:
    Restaurant(string name, string location) {
        this -> name = name;
        this -> location = location;
        this -> id = ++nextResId;
    }

    ~Restaurant() {
        cout<<"destring restaurant "<<name<<" of id "<<id<<endl;
        menu.clear();
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this -> name = name;
    }

    string getLocation() {
        return location;
    }

    void setLocation(string location) {
        this -> location = location;
    }

    void addMenuItem(MenuItem item) {
        menu.push_back(item);
    }

    vector<MenuItem> getMenu() {
        return menu;
    }
};

int Restaurant::nextResId = 0;

#endif
