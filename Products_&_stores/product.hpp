#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <cstring>
#include <iostream>

class Product
{
	public:

		Product(); //task 2.2

		Product(std::string &name_, std::string &store_, float price_); //task 2.2

		Product(const Product& product); //task 2.2

		~Product(); //task 2.2

		std::string getShop ()
		{
			return store_;
		}

		bool operator < (const Product& product) //task 2.5
		{
			return (price_ < product.price_);
		}

		friend bool operator > (const Product& product1, const Product& product2); //task 2.6

		Product& operator = (const Product& product) //task 2.7
		{
			if (this != &product)
			{
				name_=product.name_;
				store_=product.store_;
				price_=product.price_;
			}
			return *this;
		}

		Product& operator ++ () //task 2.8
		{
			price_ += 100.0;
			return *this;
		}

		friend std::ostream& operator << (std::ostream& out, const Product& product); //task 2.10
		friend std::istream& operator >> (std::istream& in, Product& product) noexcept; //task 2.10
		friend Product& operator + (Product& product, float term); //task 2.4
		friend Product& operator ++ (Product& producti, int); //task 2.9

		friend std::ostream& printShop (std::ostream& out, const Product& product);

		Product& operator - (float subtrahend) //task 2.3
		{
			price_ -= subtrahend;
			return *this;
		}	

	private:

		std::string name_; //name of product
		std::string store_; //name of store
		float price_; //price
}; 

#endif
