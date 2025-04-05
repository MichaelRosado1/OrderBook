#include "Order.h"

class MarketOrder : public BaseOrder {
	public: 
		MarketOrder(double price, int quantity, const BaseOrder::TimePoint& timePoint, Side side, TIF tif);

		MarketOrder(double price, int quantity, Side side, TIF tif);

		Side getSide();
		int getQuantity();
	private:
		Side _side;
		int _quantity;
		std::chrono::steady_clock::time_point _timeStamp;


};