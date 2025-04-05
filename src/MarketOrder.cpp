#include "MarketOrder.h"

MarketOrder::MarketOrder(double limit, int quantity, const BaseOrder::TimePoint& timePoint, Side side, TIF tif) :
	BaseOrder(quantity, timePoint, OrderType::LIMIT, side, tif) {}

MarketOrder::MarketOrder(double limit, int quantity, Side side, TIF tif) :
	BaseOrder(quantity, OrderType::LIMIT, side, tif) {}

Side MarketOrder::getSide() {
	return _side;
}

int MarketOrder::getQuantity() {
	return _quantity;
}