#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"

#include <iostream>
using namespace std;

class DeliveryOrder : public Order {
private:
    string address;

public:
    DeliveryOrder() {
        address = "";
    }

    string getType() override {
        return "Delivery";
    } 

    void setAddress(string add) {
        address = add;
    }

    string getAddress() {
        return address;
    }
};

#endif