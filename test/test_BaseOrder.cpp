#include <gtest/gtest.h>
#include "Order.h"

TEST(OrderTest, OrderConstructors) {
	auto now = std::chrono::system_clock::now();
	BaseOrder testOrder = BaseOrder(5, now, OrderType::LIMIT, Side::BUY);

	EXPECT_EQ(testOrder.getQuantity(), 5);
	EXPECT_EQ(testOrder.getTimePoint(), now);
	EXPECT_EQ(testOrder.getOrderType(), OrderType::LIMIT);
}

TEST(OrderTest, OrderQuantityChange) {
	auto now = std::chrono::system_clock::now();
	BaseOrder testOrder = BaseOrder(5, now, OrderType::LIMIT, Side::BUY);

	EXPECT_EQ(testOrder.getQuantity(), 5);
	testOrder.changeQuantity(10);
	EXPECT_EQ(testOrder.getQuantity(), 15);
	testOrder.changeQuantity(-10);
	EXPECT_EQ(testOrder.getQuantity(), 5);
}