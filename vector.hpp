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
public:
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
    //typedef std::reverse_iterator<iterator> reverse_iterator;
    //typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	vector(const allocator_type& alloc = allocator_type()) : _begin(NULL), _end(NULL), _cur(NULL), _size(0){}

    vector(size_type n, const value_type& val = value_type()) : _size(n){
        _begin = _alloc.allocate(_size);
        _end = _begin;
        while (_end != _begin + _size)
            _alloc.construct(_end++, val);
        _cur = _end;
    }

	~vector(){
        while (_cur-- != _begin)
            _alloc.destroy(_cur);
        _alloc.deallocate(_begin, size());
	}

	iterator begin() {
		return _begin;
    }

	iterator end() {
		return _cur;
	}

	size_type size() {
		return static_cast<size_type>(_cur - _begin);
	}

    size_type max_size() const {
        return _alloc.max_size();
    }

	size_type capacity() {
		return static_cast<size_type>(_end - _begin);
	}

    void push_back (const value_type& val) {
        if (_begin == NULL) {
            _begin = _alloc.allocate(1);
            _alloc.construct(_begin, val);
            _end = _begin;
            _cur = _end;
        }
        /*
        else {

        }
         */
    }

    private:
		allocator_type  _alloc;
	    pointer         _begin;
	    pointer         _end;
		pointer         _cur;
        size_type       _size;
};
};
#endif //UNTITLED1_VECTOR_HPP
