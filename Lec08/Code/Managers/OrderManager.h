#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H


#include "../model/Order.h"

#include <iostream>
#include <vector>
using namespace std;

class OrderManager {
private:
    vector<Order*> ordList;
    static OrderManager* instance;

    OrderManager() {}

public: 
    void addOrder(Order* ord) {
        ordList.push_back(ord);
    }

    static OrderManager* getInstance() {
        if (instance == nullptr) {
            instance = new OrderManager();
        }

        return instance;
    }

    void listOrder() {
        cout << "\n--- All Orders ---" << endl;
        for (auto order : ordList) {
            cout << order->getType() << " order for " << order->getUser()->getName()
                    << " | Total: ₹" << order->getTotalCost()
                    << " | At: " << order->getScheduled() << endl;
        }
    }
};

OrderManager* OrderManager::instance = nullptr;

#endif