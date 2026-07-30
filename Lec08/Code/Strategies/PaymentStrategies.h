#ifndef PAYMENT_STRATEGIES_H
#define PAYMENT_STRATEGIES_H

#include <iostream>
#include <string>

class PaymentStrategies {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategies() {}
};

#endif