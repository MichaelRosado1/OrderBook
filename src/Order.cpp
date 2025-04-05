#include "Order.h"


BaseOrder::BaseOrder(int quantity, const BaseOrder::TimePoint& timePoint, OrderType type, Side side, TIF tif)
    : _quantity(quantity), _orderType(type), _timePoint(timePoint), _side(side), _tif(tif) {}

BaseOrder::BaseOrder(int quantity, OrderType type, Side side, TIF tif)
    : _quantity(quantity), _orderType(type), _timePoint(std::chrono::system_clock::now()), _side(side), _tif(tif) {}

// Prevent copying

int BaseOrder::getQuantity() const { return _quantity; }
BaseOrder::TimePoint BaseOrder::getTimePoint() const { return _timePoint; }
OrderType BaseOrder::getOrderType() const { return _orderType; }
TIF BaseOrder::getTifType() const { return _tif; }
Side BaseOrder::getSide() const { return _side; }

std::string BaseOrder::printOrderType() const {
    switch (_orderType) {
        case OrderType::LIMIT: return "LIMIT";
        case OrderType::MARKET: return "MARKET";
        case OrderType::STOP: return "STOP";
        default: return "Unknown Type";
    }
}

void BaseOrder::changeQuantity(int quantityDelta) {
    if (_quantity + quantityDelta < 0) {
        throw std::invalid_argument("Quantity cannot be negative");
    }
    _quantity += quantityDelta;
}

void BaseOrder::setOrderType(OrderType type) {
    _orderType = type;
}

