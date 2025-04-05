#include <gtest/gtest.h>
#include "LimitOrder.h"


TEST(LimitOrderTest, LimitOrderTest) {
	auto now = std::chrono::system_clock::now();
	LimitOrder limitOrder = LimitOrder(100.23, 10, now, Side::BUY, TIF::GTC);
	EXPECT_TRUE(limitOrder.isMarketableOrder(99.99));
	EXPECT_FALSE(limitOrder.isMarketableOrder(101));
	EXPECT_EQ(limitOrder.getTimePoint(), now);
}