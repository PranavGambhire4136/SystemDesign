#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../model/DeliveryOrder.h"
#include "../model/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class NowOrderFactory : public OrderFactory {
public:
    Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems, PaymentStrategies* paymentStrategy, double totalCost, const string& orderType) override {
        Order* order = nullptr;
        if (orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setAddress(user->getAddress());
            order = deliveryOrder;
        }
        else {
            auto pickupOrder = new PickUpOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
            order = pickupOrder;
        }
        order->setUser(user);
        order->setPaymentStrategy(paymentStrategy);
        order->setCart(cart);
        order->setScheduled(TimeUtils::getCurrentTime());
        return order;
    }
};

#endif // NOW_ORDER_FACTORY_H