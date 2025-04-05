#ifndef LIMITORDER_H
#define LIMITORDER_H

#include "Order.h"

class LimitOrder : public BaseOrder {
	public:
		LimitOrder(double limit, int quantity, const BaseOrder::TimePoint& timePoint, Side side, TIF tif);

		LimitOrder(double limit, int quantity, Side side, TIF tif);



		bool isMarketableOrder(double price);

		void changeLimit(double newLimit);


	private:
		double _limit;
};

#endif