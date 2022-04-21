#include <iostream>
#include "Iterater.hpp"
#include <iterator>
#include "vector.hpp"
#include <vector>

int main() {
	{
		ft::vector<int> a(10);
		std::cout << a.size() << std::endl;
	}
	{
		std::vector<int> a(10);
		std::cout << a.size() << std::endl;
		std::vector<int>::iterator ea = a.end();
		for (std::vector<int>::iterator first = a.begin(); first != ea; first++) {
			static int i;
			*first = i++;
		}
		for (std::vector<int>::iterator first = a.begin(); first != ea; first++) {
			std::cout << *first << " ";
		}
		std::cout << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << a.capacity() << std::endl;
		a.resize(1);
		std::cout << a.size() << std::endl;
		std::cout << a.capacity() << std::endl;
		ea = a.end();
		for (std::vector<int>::iterator first = a.begin(); first != ea; ++first) {
			std::cout << *first << " ";
		}
	}
		/*
			{
				// default allocator for ints
				std::allocator< std::vector<int> > alloc;

				// demonstrating the few directly usable members
				std::vector<int>* p = alloc.allocate(1);  // space for one int
				//alloc.deallocate(p, 1);      // and it is gone
				std::cout << p << std::endl;
				// Even those can be used through traits though, so no need
				using traits_t = std::allocator_traits<decltype(alloc)>; // The matching trait
				p = traits_t::allocate(alloc, 1);
				traits_t::construct(alloc, p, 100);       // construct the int
				alloc.destroy(p);
				std::cout << p->size() << '\n';
				traits_t::deallocate(alloc, p, 1);      // deallocate space for one int
			}
		 */
	return 0;
}