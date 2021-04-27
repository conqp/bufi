#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <sstream>

template <class T>
std::string join(std::vector<T> vec, std::string delim)
{
	long unsigned int size = vec.size();

	switch (size)
	{
		case 0:
			return "";
		case 1:
			return std::to_string(vec[0]);
		default:
			std::ostringstream os;

			for (long unsigned int i = 0; i < size - 1; i++)
				os << vec[i] << delim;

			os << vec[size-1];
			return os.str();
	}
}

#endif
