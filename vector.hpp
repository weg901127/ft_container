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
class v_iter {
public:
    typedef T                                                                               iterator_type;
    typedef typename ft::iterator_traits<iterator_type>::iterator_category                  iterator_category;
    typedef typename ft::iterator_traits<iterator_type>::value_type                         value_type;
    typedef typename ft::iterator_traits<iterator_type>::difference_type                    difference_type;
    typedef typename ft::iterator_traits<iterator_type>::pointer                            pointer;
    typedef typename ft::iterator_traits<iterator_type>::reference                          reference;

    v_iter(void){}
    v_iter(iterator_type __x) : _elem(__x) {}
    template <class It>
    v_iter(const v_iter<It> & elem, typename enable_if<is_convertible<It, iterator_type>::value>::type* = 0)
        : _elem(elem.base()) {}
    v_iter(const v_iter& __x) : _elem(__x.base()) {}

    reference   operator*() const {return *_elem;}
    pointer     operator->() const {return &_elem;}

    iterator_type base() const {
        return _elem;
    }
    v_iter& operator++() {
        _elem++;
        return (*this);
    }
    v_iter  operator++(int) {
        v_iter tmp(*this);
        operator++();
        return tmp;
    }
    v_iter& operator--() {
        _elem--;
        return (*this);
    }
    v_iter  operator--(int) {
        v_iter tmp(*this);
        operator--();
        return tmp;
    }
    v_iter  operator+ (difference_type n) const {
        v_iter __w(*this); __w += n; return __w;
    }
    v_iter& operator+=(difference_type n) {
        _elem += n; return *this;
    }
    v_iter operator- (difference_type n) const {
        return *this + (-n);
    }
    v_iter& operator-=(difference_type n) {
        *this += -n; return *this;
    }
    reference operator[](difference_type n) const {
        return _elem[n];
    }
//    operator v_iter<const T> () const
//    { return (v_iter<const T>(this->_elem)); }
private:
    iterator_type _elem;
};

template <class _Iter1>
bool operator==(const v_iter<_Iter1>& __x, const v_iter<_Iter1>& __y) {return __x.base() == __y.base();}

template <class _Iter1, class _Iter2>
bool operator==(const v_iter<_Iter1>& __x, const v_iter<_Iter2>& __y) {return __x.base() == __y.base();}

template <class _Iter1>
bool operator<(const v_iter<_Iter1>& __x, const v_iter<_Iter1>& __y) {return __x.base() < __y.base();}

template <class _Iter1, class _Iter2>
bool operator<(const v_iter<_Iter1>& __x, const v_iter<_Iter2>& __y) {return __x.base() < __y.base();}

template <class _Iter1>
bool operator!=(const v_iter<_Iter1>& __x, const v_iter<_Iter1>& __y) {return !(__x == __y);}

template <class _Iter1, class _Iter2>
bool operator!=(const v_iter<_Iter1>& __x, const v_iter<_Iter2>& __y) {return !(__x == __y);}

template <class _Iter1>
bool operator>(const v_iter<_Iter1>& __x, const v_iter<_Iter1>& __y) {return __y < __x;}

template <class _Iter1, class _Iter2>
bool operator>(const v_iter<_Iter1>& __x, const v_iter<_Iter2>& __y) {return __y < __x;}

template <class _Iter1>
bool operator>=(const v_iter<_Iter1>& __x, const v_iter<_Iter1>& __y) {return !(__x < __y);}

template <class _Iter1, class _Iter2>
bool operator>=(const v_iter<_Iter1>& __x, const v_iter<_Iter2>& __y) {return !(__x < __y);}

template <class _Iter1>
bool operator<=(const v_iter<_Iter1>& __x, const v_iter<_Iter1>& __y) {return !(__y < __x);}

template <class _Iter1, class _Iter2>
bool operator<=(const v_iter<_Iter1>& __x, const v_iter<_Iter2>& __y) {return !(__y < __x);}

template <class _Iter1, class _Iter2>
typename v_iter<_Iter1>::difference_type
operator-(const v_iter<_Iter1>& __x, const v_iter<_Iter2>& __y) {return __x.base() - __y.base();}

template <class _Iter1>
v_iter<_Iter1> operator+(typename v_iter<_Iter1>::difference_type __n, v_iter<_Iter1> __x) {__x += __n;return __x;}

template < class T, class Alloc = std::allocator<T> >
    class vector {
public:
    typedef T                                               value_type;
    typedef Alloc                                           allocator_type;
    typedef typename allocator_type::reference              reference;
    typedef typename allocator_type::const_reference        const_reference;
    typedef typename std::allocator_traits<allocator_type>  _alloc_traits;
    typedef typename _alloc_traits::size_type               size_type;
    typedef typename _alloc_traits::difference_type         difference_type;
    typedef typename _alloc_traits::pointer                 pointer;
    typedef typename _alloc_traits::const_pointer           const_pointer;
    typedef ft::v_iter<pointer>                             iterator;
    typedef ft::v_iter<const_pointer>                       const_iterator;
    typedef ft::reverse_iterator<iterator>                 reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>           const_reverse_iterator;

    vector(const allocator_type& alloc = allocator_type()) : _begin(NULL), _end(NULL), _cur(NULL) {}
    vector(size_type n, const value_type& val = value_type()) {
        _begin = _alloc.allocate(n);
        _end = _begin;
        while (_end != _begin + n)
            _alloc.construct(_end++, val);
        _cur = _end;
    }
    vector(size_type n, const value_type& val, const allocator_type& alloc) : _begin(NULL), _end(NULL), _cur(NULL){
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

    const_iterator begin() const{
        return iterator(_begin);
    }

    const_iterator end() const{
        return iterator(_cur);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const{
        return const_reverse_iterator(end());
    }

	size_type size() const {
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

	size_type capacity() const {
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
        if (n >= size())
            throw std::out_of_range("vector");
        return _begin[n];
    }

    const_reference at (size_type n) const{
        if (n >= size())
            throw std::out_of_range("vector");
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
        /*
        if (_begin != NULL) {
            while (_cur-- != _begin)
                _alloc.destroy(_cur);
            _alloc.deallocate(_begin, size());
        }
        std::copy(first, last, _begin);
         */
        /*
        _alloc_traits::deallocate(this->_alloc, this->begin(), capacity());
        clear();
        difference_type __ns = distance(first, last);
        const   size_t __n = static_cast<size_type>(__ns);
    */
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

    void swap (vector<value_type, Alloc> & x, vector<value_type, Alloc> & y) {
        x.swap(y);
    }

    friend bool    operator==(vector<value_type, Alloc> & x, vector<value_type, Alloc> & y){
        const typename vector<value_type, Alloc>::size_type __sz = x.size();
        return __sz == y.size() && x.begin() == y.begin();
    }

    iterator insert (const_iterator position, const value_type& val) {
        /*
        iterator __r;
        if (size() < capacity())
        {
            const_iterator __old_end = end();
            ++__size_;
            _VSTD::copy_backward(__position, __old_end, end());
            __r = __const_iterator_cast(__position);
        }
        else
        {
            vector __v(__alloc());
            __v.reserve(__recommend(__size_ + 1));
            __v.__size_ = __size_ + 1;
            __r = _VSTD::copy(cbegin(), __position, __v.begin());
            _VSTD::copy_backward(__position, cend(), __v.end());
            swap(__v);
        }
        *__r = __x;
        return __r;
        */
    }

    void insert (const_iterator position, size_type n, const value_type& val) {

    }

    template <class InputIterator>
    void insert (const_iterator position, InputIterator first, InputIterator last) {

    }

    void    swap(vector<value_type, Alloc> & x) {
        pointer         tmp;
        allocator_type  tmp_alloc;

        tmp = this->_begin;
        this->_begin = x._begin;
        x._begin = tmp;
        tmp = this->_end;
        this->_end = x._end;
        x._end = tmp;
        tmp = this->_cur;
        this->_cur = x._cur;
        x._cur = tmp;
        tmp_alloc = this->_alloc;
        this->_alloc = x._alloc;
        x._alloc = tmp_alloc;
    }

    private:
        void clear() {_end = 0;}
        void __vdeallocate() {
            if (this->__begin_ != NULL)
            {
                clear();
                _alloc_traits::deallocate(this->_alloc, this->begin(), capacity());
                this->__begin_ = this->__end_ = this->__end_cap() = NULL;
            }
        }

        void __vallocate(size_type __n)
        {
            if (__n > max_size())
                this->__throw_length_error();
            this->__begin_ = this->__end_ = _alloc_traits::allocate(this->_alloc, __n);
            this->__end_cap() = this->__begin_ + __n;
        }

        //todo 분리 예정
        template <class _InputIter>
        typename iterator_traits<_InputIter>::difference_type
        __distance(_InputIter __first, _InputIter __last, input_iterator_tag)
        {
            typename iterator_traits<_InputIter>::difference_type __r(0);
            for (; __first != __last; ++__first)
                ++__r;
            return __r;
        }

        template <class _RandIter>
        typename iterator_traits<_RandIter>::difference_type
        __distance(_RandIter __first, _RandIter __last, random_access_iterator_tag)
        {
            return __last - __first;
        }

        template <class _InputIter>
        typename iterator_traits<_InputIter>::difference_type
        distance(_InputIter __first, _InputIter __last)
        {
            return __distance(__first, __last, typename iterator_traits<_InputIter>::iterator_category());
        }
    private:
		allocator_type  _alloc;
	    pointer         _begin;
	    pointer         _end;
		pointer         _cur;
};

}
#endif //VECTOR_HPP
//todo distance 라이브러리에서 찾아보기