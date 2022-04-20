#include <iostream>
#include "Iterater.hpp"
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> *a = new std::vector<int>;
    ft::iterator<std::vector<int>, int> k = std::iterator<std::vector<int>, int>;
    return 0;
}