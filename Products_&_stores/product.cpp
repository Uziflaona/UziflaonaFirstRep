#include "product.hpp"
#include "invalidproduct.hpp"
#include <iomanip>

Product::Product(): //task 2.2
	price_{0}
{
}

Product::Product(std::string& name_, std::string& store_, float price_): //task 2.2
	
	name_(name_),
	store_(store_),
	price_(price_)
	{
	}

Product::Product(const Product& product): //task 2.2
	name_(product.name_),
	store_(product.store_),
	price_(product.price_)
	{
	}

Product::~Product() //task 2.2
{
}

//Product& Product::operator = (const Product& product)
//{
//	if (this != &product)
//	{
//		name_=product.name_;
//		store_=product.store_;
//		price_=product.price_;
//	}
//	return *this;
//}

//bool Product::operator < (const Product& product)
//{
//	return (price_ < product.price_);
//}

Product& operator + (Product& product, float term) //task 2.4
{
	product.price_ += term;
	return product;
}

std::ostream& operator << (std::ostream& out, const Product& product) //task 2.10
{
	out.width(30);
	out << product.name_;
	out.width(30);
	out << product.store_;
	out.width(10);
	out << product.price_ << " rub.";
	return out;
}

std::istream& operator >> (std::istream& in, Product& product) noexcept //task 2.10
{
	in >> product.name_;
	in >> product.store_;
	in >> product.price_;
	return in;
}

bool operator > (const Product& product1, const Product& product2) //task 2.6
{
	return (product1.price_ > product2.price_);
}

Product& operator ++ (Product& product, int d) //task 2.9
{
	product.price_ += 1000.0;
	return product;
}

std::ostream& printShop (std::ostream& out, const Product& product) //task 6
{
	out.width(50);
	out << product.name_;
	out.width(15);
	out << product.price_ << " rub.";
	return out;
}
