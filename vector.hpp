//
// Created by gilee on 2022/04/13.
//

#ifndef UNTITLED1_VECTOR_HPP
#define UNTITLED1_VECTOR_HPP

#include <memory>
#include <vector>
namespace ft{
template < class T, class Alloc = std::allocator<T> >
class vector {
protected:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename std::allocator_traits<allocator_type> _alloc_traits;
    typedef typename _alloc_traits::pointer iterator;
    typedef typename _alloc_traits::const_pointer const_iterator;
    typedef typename _alloc_traits::size_type size_type;
    typedef typename _alloc_traits::difference_type difference_type;
    typedef typename _alloc_traits::pointer pointer;
    typedef typename _alloc_traits::const_pointer const_pointer;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
public:
    iterator begin() {
        return NULL;
    }

    const_iterator begin() const {
        return NULL;
    }
};
};
#endif //UNTITLED1_VECTOR_HPP
