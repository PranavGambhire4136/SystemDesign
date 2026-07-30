#ifndef ORDER_FACTORY
#define ORDER_FACTORY

#include <iostream>
#include "../model/User.h"
#include "../Strategies/PaymentStrategies.h"
#include "../model/Order.h"

#include <vector>
#include <string>
using namespace std;

class OrderFactory {
public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems,
                                PaymentStrategies* paymentStrategy, double totalCost, const string& orderType) = 0;
};

#endif