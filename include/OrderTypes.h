#pragma once 

enum OrderType {
	LIMIT,
	MARKET,
	STOP,
};

enum Side {
	BUY,
	SELL,
};

enum TIF {
	GTC,
	FOK,
	IOC,
};