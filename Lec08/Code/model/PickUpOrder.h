#ifndef PICK_UP_ORDER_H
#define PICK_UP_ORDER_H

#include "Order.h"

#include <iostream>
#include <string>
using namespace std;

class PickUpOrder : public Order {
private:
    string restaurantAddress;

public:
    PickUpOrder() {
        restaurantAddress = "";
    }

    void setRestaurantAddress(string address) {
        restaurantAddress = address;
    }

    string getRestaurantAddress() {
        return restaurantAddress;
    }

    string getType() {
        return "Pick Up";
    }
};

#endif