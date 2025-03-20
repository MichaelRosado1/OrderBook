#include <iostream>
#include <chrono>
#include <stdexcept>  // For exception handling
#include "OrderTypes.h"

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
using TimeStamp = std::time_t;

class Order {
    public:
        explicit Order(double price, int quantity, const TimePoint& timePoint, OrderType type)
            : _price(price), _quantity(quantity), _orderType(type) {
            _timeStamp = std::chrono::system_clock::to_time_t(timePoint);
        }

        explicit Order(double price, int quantity, OrderType type)
            : _price(price), _quantity(quantity), _orderType(type) {
            _timeStamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        }

        // Prevent copying
        Order(const Order&) = delete;
        Order& operator=(const Order&) = delete;

        double getPrice() const { return _price; }
        int getQuantity() const { return _quantity; }
        TimeStamp getTimeStamp() const { return _timeStamp; }
        OrderType getOrderType() const { return _orderType; }

        void changeQuantity(int quantityDelta) {
            if (_quantity + quantityDelta < 0) {
                throw std::invalid_argument("Quantity cannot be negative");
            }
            _quantity += quantityDelta;
        }

        void setOrderType(OrderType type) {
            _orderType = type;
        }

    private:
        double _price;
        int _quantity;
        TimeStamp _timeStamp;
        OrderType _orderType;
};
