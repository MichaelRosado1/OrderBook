#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <chrono>
#include "OrderTypes.h"
class Order {
public:
    Order(double getPrice, int getQuantity, const TimePoint& timePoint, OrderType type);
    Order(double getPrice, int getQuantity, OrderType type);

    // Delete copy constructor and copy assignment operator
    Order(const Order&) = delete;
    Order& operator=(const Order&) = delete;

    // Getters
    double getPrice() const;
    int getQuantity() const;
    TimeStamp getTimeStamp() const;
    OrderType getOrderType() const;

    // Modifiers
    void changeQuantity(int quantityDelta);
    void setOrderType(OrderType type);

private:
    double _price;
    int _quantity;
    TimeStamp _timeStamp;
    OrderType _orderType;
};

#endif // ORDER_H
