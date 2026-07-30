#ifndef PAY_BY_CASH_STRATEGIES_H
#define PAY_BY_CASH_STRATEGIES_H

#include "PaymentStrategies.h"

#include <iostream>
using namespace std;

class PayBYCashStrategies : public PaymentStrategies {
    void pay(double amount) override {
        cout<<"User will pay "<<amount<<" by cash";
    }
};

#endif