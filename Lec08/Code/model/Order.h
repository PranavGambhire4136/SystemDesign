#ifndef ORDER_H
#define ORDER_H

#include "Cart.h"
#include "User.h"
#include "../Strategies/PaymentStrategies.h"

#include <iostream>
using namespace std;

class Order{
private:
    int id; 
    Cart* cart;
    User* user;
    string scheduled;
    static int nextOrderId;

    PaymentStrategies* payStr;

public:
    Order() {
        user = nullptr;
        payStr = nullptr;
        scheduled = "";
        id = ++nextOrderId;
    }

    virtual ~Order() {
        delete payStr;
    }

     bool processPayment() {
        if (payStr) {
            payStr->pay(cart -> getTotalCost());
            return true;
        } else {
            cout << "Please choose a payment mode first" << endl;
            return false;
        }
    }

    User* getUser() {
        return user;
    }

    void setUser(User* u) {
        user = u;
    }

    void setPaymentStrategy(PaymentStrategies* p) {
        payStr = p;
    }

    double getTotalCost() {
        return cart -> getTotalCost();
    }

    string getScheduled() {
        return scheduled;
    }

    void setScheduled(string s) {
        scheduled = s;
    }

    void setCart(Cart* c) {
        cart = c;
    }

    Cart* getCart() {
        return cart;
    }

    int getOrderId() {
        return id;
    }

    virtual string getType() = 0;
};

int Order::nextOrderId = 0;

#endif