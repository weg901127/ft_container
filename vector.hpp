//
// Created by gilee on 2022/04/13.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include "iterater.hpp"
//#include <vector>
namespace ft{
template<typename T>
class v_iter : ft::iterator<ft::random_access_iterator_tag, T> {
public:
    //typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
    //typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
    //typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
    typedef T*                                                                              pointer;
    typedef T&                                                                              reference;

    v_iter(void):_elem(){}
    v_iter(pointer elem):_elem(elem){}
    v_iter& operator++() {
        _elem++;
        return (*this);
    }
    v_iter  operator++(int) {
        v_iter tmp(*this);
        operator++();
        return tmp;
    }

    reference operator*() const {
        return (*_elem);
    }
//    operator v_iter<const T> () const
//    { return (v_iter<const T>(this->_elem)); }
private:
    pointer _elem;
};
template < class T, class Alloc = std::allocator<T> >
    class vector {
public:
    typedef T                                               value_type;
    typedef Alloc                                           allocator_type;
    typedef typename allocator_type::reference              reference;
    typedef typename allocator_type::const_reference        const_reference;
    typedef typename std::allocator_traits<allocator_type>  _alloc_traits;
    typedef typename _alloc_traits::size_type               size_type;
    //typedef typename _alloc_traits::difference_type         difference_type;
    typedef typename _alloc_traits::pointer                 pointer;
    //typedef typename _alloc_traits::const_pointer           const_pointer;
    typedef ft::v_iter<value_type>                          iterator;
    typedef ft::v_iter<value_type>                          const_iterator;
    //typedef std::reverse_iterator<iterator>                 reverse_iterator;
    //typedef std::reverse_iterator<const_iterator>           const_reverse_iterator;

    vector(const allocator_type& alloc = allocator_type()) : _begin(NULL), _end(NULL), _cur(NULL) {}
    vector(size_type n, const value_type& val = value_type()) {
        _begin = _alloc.allocate(n);
        _end = _begin;
        while (_end != _begin + n)
            _alloc.construct(_end++, val);
        _cur = _end;
    }
	~vector(){
        while (_cur-- != _begin)
            _alloc.destroy(_cur);
        _alloc.deallocate(_begin, size());
	}
    /*
    vector(vector const& x) {
        *this = x;
    }
     */
    vector& operator=(const vector& x) {
        while (_cur-- != _begin)
            _alloc.destroy(_cur);
        _alloc.deallocate(_begin, size());
        std::copy(x._begin, x._end, _begin);
        _cur = x._cur;
        _end = x._end;
    }

    reference operator[](size_type n) {
        return _begin[n];
    }

    const_reference operator[](size_type n) const {
        return _begin[n];
    }

	iterator begin() {
		return iterator(_begin);
    }

	iterator end() {
		return iterator(_cur);
	}

	size_type size() {
		return static_cast<size_type>(_cur - _begin);
	}

    bool empty(void) const {
        return (_begin == _cur);
    }

    void resize (size_type n, value_type val = value_type()) {
        if (n > capacity()) {
            pointer tmp = _alloc.allocate(n);
            pointer tmp_end = tmp + n;
            pointer tmp_cur = tmp + (_cur - _begin);
            std::copy(_begin, _cur, tmp);
            while (tmp_end-- != tmp_cur)
                _alloc.construct(tmp_end, val);
            while (_cur-- != _begin)
                _alloc.destroy(_cur);
            _alloc.deallocate(_begin, size());
            _begin = tmp;
            _cur = _begin + n;
            _end = _begin + n;
        } else if (n <= size()) {
            pointer tmp_cur = _cur;
            while (tmp_cur-- != _begin + n) {
                _alloc.destroy(tmp_cur);
            }
            _cur = _begin + n;
        }
        else {
            size_type i = n - size();
            while (i--)
                push_back(val);
        }
    }

    size_type max_size() const {
        return _alloc.max_size();
    }

	size_type capacity() {
		return static_cast<size_type>(_end - _begin);
	}

    allocator_type get_allocator() const {
        return _alloc;
    }

    void push_back (const value_type& val) {
        if (_begin == NULL) {
            _begin = _alloc.allocate(1);
            _end = _begin + 1;
            _cur = _begin;
        }
        else if (size() == capacity()) {
            pointer tmp_p = _alloc.allocate(size() * 2);
            std::copy(_begin, _end, tmp_p);
            while (_cur-- != _begin)
                _alloc.destroy(_cur);
            _alloc.deallocate(_begin, size());
            _cur = tmp_p + (_end - _begin);
            _begin = tmp_p;
            _end = _begin + (size() * 2);
        }
        _alloc.construct(_cur, val);
        _cur++;
    }

    void pop_back() {
        if (!empty())
            _alloc.destroy(--_cur);
    }

    reference at (size_type n) {
        if (n > size())
            throw std::out_of_range("out of range!\n");
        return _begin[n];
    }

    const_reference at (size_type n) const{
        if (n > size())
            throw std::out_of_range("out of range!\n");
        return _begin[n];
    }

    reference front() {
        return *_begin;
    }

    const_reference front() const {
        return *_begin;
    }

    reference back() {
        return *(_cur - 1);
    }

    const_reference back() const {
        return *(_cur - 1);
    }

    template <class InputIterator>
    void assign (InputIterator first, InputIterator last) {
        if (_begin != NULL) {
            while (_cur-- != _begin)
                _alloc.destroy(_cur);
            _alloc.deallocate(_begin, size());
        }
        std::copy(first, last, _begin);
    }

    void assign (size_type n, const value_type& val) {
        if (_begin != NULL) {
            while (_cur-- != _begin)
                _alloc.destroy(_cur);
            _alloc.deallocate(_begin, size());
        }
        _begin = _alloc.allocate(n);
        _end = _begin;
        while (_end != _begin + n)
            _alloc.construct(_end++, val);
        _cur = _end;
    }
/*
    iterator insert (iterator position, const value_type& val) {

    }

    void insert (iterator position, size_type n, const value_type& val) {

    }

    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last) {

    }
*/
    private:
		allocator_type  _alloc;
	    pointer         _begin;
	    pointer         _end;
		pointer         _cur;
};

}
#endif //VECTOR_HPP
//todo distance 라이브러리에서 찾아보기