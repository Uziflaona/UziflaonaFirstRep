#ifndef INVALIDPRODUCT_HHP
#define INVALIDPRODUCT_HPP

#include <exception>

class InvalidProduct : public std::exception
{
	public:
		virtual const char* what() const noexcept
		{
			return "Invalid product";
		}
};

#endif
