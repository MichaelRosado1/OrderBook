#include <iostream>
#include <chrono> 
#include "Order.h"

int main() {
	/*
		The first implementation of the order book will be simple
		
		I'm going to have buys and sells listed by price level 
	*/
	BaseOrder myOrder = BaseOrder(34, std::chrono::system_clock::now(), OrderType::LIMIT, Side::BUY);

	std::cout << myOrder.getQuantity() << "\n";
	std::cout << myOrder.getOrderType() << "\n";
	std::cout << myOrder.printOrderType() << "\n";
	return 0;
}