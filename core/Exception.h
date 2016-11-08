#pragma once

#include <exception>
#include <string>

namespace Actinium
{
	class Exception
	{
	public:
		Exception(const std::string &what)
		{
			this->isWhat = what;
		}
		virtual const char* what() const throw()
		{
			return this->isWhat.c_str();
		}
	private:
		std::string isWhat;
	};
}
