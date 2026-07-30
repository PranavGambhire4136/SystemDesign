#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../model/DeliveryOrder.h"
#include "../model/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class ScheduledOrderFactory : public OrderFactory {
private:
    string scheduleTime;
public:
    ScheduledOrderFactory(string scheduleTime) {
        this->scheduleTime = scheduleTime;
    }

    Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems,
                        PaymentStrategies* paymentStrategy, double totalCost, const string& orderType) override {
        Order* order = nullptr;

        if(orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setAddress(user->getAddress());
            order = deliveryOrder;
        } 
        else {
            auto pickupOrder = new PickUpOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
        }
        order->setUser(user);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(scheduleTime);
        order -> setCart(cart);
        return order;
    }
};

#endif // SCHEDULED_ORDER_FACTORY_H