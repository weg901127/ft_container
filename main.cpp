#include <iostream>
#include "Iterater.hpp"
#include <iterator>
#include "vector.hpp"
#include <vector>

int main() {
	{
		ft::vector<int> a(10);
		ft::vector<int> b;
		ft::vector<int>::iterator c = a.begin();
		std::cout << c << std::endl;
	}
	return 0;
}