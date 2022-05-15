#include <iostream>
#include "iterater.hpp"
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

TEST(vector, push_back_0) {
    ft::vector<int> a;
    std::vector<int> b;
    a.push_back(9176);
    a.push_back(1);
    b.push_back(9176);
    b.push_back(1);
    std::cout << a.size() << " " << a.capacity() << std::endl;
    std::cout << b.size() << " " << b.capacity() << std::endl;
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.capacity(), b.capacity());
    ft::vector<int>::iterator c = a.begin();
    std::vector<int>::iterator d = b.begin();
    EXPECT_EQ(*c++, *d++);
    EXPECT_EQ(*c, *d);
}

TEST(vector, push_back_1) {
    ft::vector<int> a(12322123);
    std::vector<int> b(12322123);
    a.push_back(1);
    b.push_back(1);
    std::cout << a.size() << " " << a.capacity() << std::endl;
    std::cout << b.size() << " " << b.capacity() << std::endl;
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.capacity(), b.capacity());
    ft::vector<int>::iterator c = a.begin();
    std::vector<int>::iterator d = b.begin();
    EXPECT_EQ(*c++, *d++);
    EXPECT_EQ(*c, *d);
}

TEST(vector, resize_0) {
    ft::vector<int> a(5, 10);
    std::vector<int> b(5, 10);
    b.resize(10);
    a.resize(10);
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.capacity(), b.capacity());
    b.resize(3);
    a.resize(3);
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.capacity(), b.capacity());
    b.resize(3092, 9292);
    a.resize(3092, 9292);
    EXPECT_EQ(a.size(), b.size());
    EXPECT_EQ(a.capacity(), b.capacity());
    ft::vector<int>::iterator c = a.begin();
    std::vector<int>::iterator d = b.begin();
    for (int i = 0; i < a.size(); i++) {
        EXPECT_EQ(*c++, *d++);
    }
    b.resize(2, 3);
    a.resize(2, 3);
    for (int i = 0; i < a.size(); i++) {
        EXPECT_EQ(*c++, *d++);
    }
}

TEST(vector, pop_back_0) {
    ft::vector<int> a(100);
    std::vector<int> b(100);
    a.pop_back();
    b.pop_back();
    std::cout << a.size() << " " << a.capacity() << std::endl;
    std::cout << b.size() << " " << b.capacity() << std::endl;
    std::cout << a.max_size() << " " << b.max_size() << std::endl;
}
