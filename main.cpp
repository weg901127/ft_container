#include <iostream>
#include "Iterater.hpp"
#include <iterator>
#include "vector.hpp"
#include <vector>

int main() {
	{
		ft::vector<int> a(10);
		ft::vector<int>::iterator b = a.begin();
		ft::vector<int>::iterator c = a.end();
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		for (b; b != c; b++) {
			*b = 1;
		}
		for (b = a.begin(); b != c; b++) {
			std::cout << *b << " ";
		}
		std::cout << std::endl;
	}
	{
		std::vector<int> a(10);
		std::vector<int>::iterator b = a.begin();
		std::vector<int>::iterator c = a.end();
		//std::cout << b << std::endl;
		//std::cout << c << std::endl;
		for (b; b != c; b++) {
			*b = 1;
		}
		for (b = a.begin(); b != c; b++) {
			std::cout << *b << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}