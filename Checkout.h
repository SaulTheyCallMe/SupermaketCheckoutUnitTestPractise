#pragma once
#include <string>
#ifndef CHECKOUT_H_
#define CHECKOUT_H_
#include <map>
class Checkout{
public:
	Checkout();
	virtual ~Checkout();

	void addItemPrice(std::string item, int price);
	void addItem(std::string item);
	void addDiscount(std::string item, int nbrOfItems, int DiscountPrice);
	int calculateTotal();
protected:
	struct Discount {
		int nbrOfItems;
		int DiscountPrice;
	};
	std::map<std::string, int> prices;
	std::map<std::string, Discount> discounts;
	std::map<std::string, int> items;
	int total;

	void calculateItem(std::string item, int itemCnt);
	void calculateDiscount(std::string item, int itemCnt, Discount discount);
};

#endif
