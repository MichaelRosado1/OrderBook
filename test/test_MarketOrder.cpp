#include <gtest/gtest.h>
#include "MarketOrder.h"

TEST(MarketOrderTest, MarketOrderSimpleTest) {
	auto now = std::chrono::system_clock::now();

	MarketOrder order = MarketOrder(100, 10, Side::BUY, TIF::GTC);
	EXPECT_EQ(order.getSide, Side::BUY)
}