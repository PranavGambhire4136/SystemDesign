#ifndef PAY_BY_UPI_STRATEGIES_H
#define PAY_BY_UPI_STRATEGIES_H

#include "PaymentStrategies.h"

#include <iostream>
#include <string>

using namespace std;

class UPIStrategies : public PaymentStrategies {

    string mobile;
public:
    void pay(double amount) override {
        cout << "Paid $" << amount << " using UPI (" << mobile << ")" << endl;
    }

    UPIStrategies(string mob) {
        mobile = mob;
    }
};

#endif