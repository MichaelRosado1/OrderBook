#include "Order.h"

class StopOrder : public BaseOrder {
	public:
		StopOrder(double price, double limit, int quantity, const BaseOrder::TimePoint& timePoint, Side side, TIF tif);

		StopOrder(double price, double limit, int quantity, Side side, TIF tif);
	private:
}