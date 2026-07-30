#ifndef Cart_h
#define Cart_h

#include "MenuItem.h"
#include "Restaurant.h"

#include <iostream>
#include <vector>
using namespace std;

class Cart {
private:
    vector<MenuItem> items;
    Restaurant* res;
    double total;

public:
    Cart() {
        res = nullptr;
        total = 0;
    }

    void setRestaurant(Restaurant* res) {
        this -> res = res;
    }

    Restaurant* getRestaurant() {
        return res;
    }

    void addItem(const MenuItem &item){
        items.push_back(item);
        total += item.getPrice();
    }

    vector<MenuItem>& getItems() {
        return items;
    }

    double getTotalCost() {
        return total;
    }

    bool isEmpty() {
        return items.size() == 0;
    }

    void clear() {
        while (items.size() !=  0) {
            items.pop_back();
            total = 0;
        }
    }
};

#endif