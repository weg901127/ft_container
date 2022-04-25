#include <iostream>
#include "Iterater.hpp"
#include <iterator>
#include "vector.hpp"
#include <vector>
#include "gtest/gtest.h"

TEST(vector, size_test_no_args) {
    ft::vector<int> a;
    std::vector<int> b;
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.capacity(), b.capacity());
    EXPECT_EQ(a.max_size(), b.max_size());
}

TEST(vector, size_test_with_args_2) {
    ft::vector<int> a(10, 10);
    std::vector<int> b(10, 10);
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.capacity(), b.capacity());
    EXPECT_EQ(a.max_size(), b.max_size());
}


TEST(vector, iter_test_with_args_2) {
    ft::vector<int> a(10, 10);
    std::vector<int> b(10, 10);
    ft::vector<int>::iterator ia = a.begin();
    std::vector<int>::iterator ib = b.begin();
    int size = a.size();
    while (size--) {
        EXPECT_EQ(*ia++, *ib++);
    }
}

TEST(vector, size_test_with_args_container) {
    ft::vector<std::vector<int>> a(10, std::vector<int>(10));
    std::vector<std::vector<int>> b(10, std::vector<int>(10));
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.capacity(), b.capacity());
    EXPECT_EQ(a.max_size(), b.max_size());
}

TEST(vector, iter_test_with_args_2_container) {
    ft::vector<std::vector<int>> a(10, std::vector<int>(10));
    std::vector<std::vector<int>> b(10, std::vector<int>(10));
    ft::vector<std::vector<int>>::iterator ia = a.begin();
    std::vector<std::vector<int>>::iterator ib = b.begin();
    int size = a.size();
    while (size--) {
        EXPECT_EQ(*ia++, *ib++);
    }
}

TEST(vector, iter_test_no_args) {
    EXPECT_DEATH({
         ft::vector<int> a;
         ft::vector<int>::iterator ia = a.begin();
         std::cout << *ia << std::endl;
        }, ".*");
    EXPECT_DEATH({
         std::vector<int> b;
         std::vector<int>::iterator ib = b.begin();
        std::cout << *ib << std::endl;
        }, ".*");
}

TEST(vector, push_back) {
    ft::vector<int> a;
    std::vector<int> b(3);
    for (int i = 0; i < 2; i++) {
        b.push_back(i);
    }
    std::cout << a.size() << " " << b.size() << std::endl;
    std::cout << a.capacity() << " " << b.capacity() << std::endl;
    //EXPECT_EQ(a.size(), b.size());
    //EXPECT_EQ(a.capacity(), b.capacity());
    //EXPECT_EQ(a.max_size(), b.max_size());
}
