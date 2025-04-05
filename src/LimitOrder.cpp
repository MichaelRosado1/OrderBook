#include "LimitOrder.h"

LimitOrder::LimitOrder(double limit, int quantity, const BaseOrder::TimePoint& timePoint, Side side, TIF tif) :
	_limit(limit), BaseOrder(quantity, timePoint, OrderType::LIMIT, side, tif) {}

LimitOrder::LimitOrder(double limit, int quantity, Side side, TIF tif) :
	_limit(limit), BaseOrder(quantity, OrderType::LIMIT, side, tif) {}

bool LimitOrder::isMarketableOrder(double price) {
	// this changes based on the side
	Side side = this->getSide();
	if (side == Side::BUY) {
		// this means that we want either the market price or lower
		if (price <= _limit) {
			return true;
		}
	} else if (side == Side::SELL) {
		if (price >= _limit) {
			return true;
		}
	}
	return false;
}

void LimitOrder::changeLimit(double newLimit) {
	_limit = newLimit;
}

