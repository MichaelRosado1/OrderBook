#ifndef ORDER_H
#define ORDER_H
#pragma once

#include <stdexcept>  // For exception handling
#include <iostream>
#include <chrono>
#include "OrderTypes.h"


class BaseOrder {
public:
    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
    using TimeStamp = std::time_t;
    BaseOrder(int quantity, const TimePoint& timePoint, OrderType type, Side side, TIF tif = TIF::GTC);
    BaseOrder(int quantity, OrderType type, Side side, TIF tif);

    // Delete copy constructor and copy assignment operator
    BaseOrder(const BaseOrder&) = delete;
    BaseOrder& operator=(const BaseOrder&) = delete;

    // move
    BaseOrder(BaseOrder&&) = default;
    BaseOrder& operator=(BaseOrder&&) = default;

    // Getters
    int getQuantity() const;
    TimePoint getTimePoint() const;
    OrderType getOrderType() const;
    TIF getTifType() const;
    Side getSide() const;
    std::string printOrderType() const;

    // Modifiers
    void changeQuantity(int quantityDelta);
    void setOrderType(OrderType type);

private:
    int _quantity;
    TimePoint _timePoint;
    OrderType _orderType;
    Side _side;
    TIF _tif;
};

#endif // ORDER_H
