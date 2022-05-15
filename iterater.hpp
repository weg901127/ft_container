//
// Created by gilee on 2022/04/20.
//

#ifndef UNTITLED1_ITERATER_HPP
#define UNTITLED1_ITERATER_HPP

#include <cstddef>

namespace ft {
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public ft::input_iterator_tag {};
    struct bidirectional_iterator_tag : public ft::forward_iterator_tag {};
    struct random_access_iterator_tag : public ft::bidirectional_iterator_tag {};

    template<class Iterator>
    struct iterator_traits {
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template<class T>
    struct iterator_traits<T *> {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template<class Category, class T, class Distance = ptrdiff_t,
            class Pointer = T *, class Reference = T &>
    struct iterator {
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    template <class Iterator>
    class reverse_iterator
: public iterator<typename ft::iterator_traits<Iterator>::iterator_category,
                    typename ft::iterator_traits<Iterator>::value_type,
                    typename ft::iterator_traits<Iterator>::difference_type,
                    typename ft::iterator_traits<Iterator>::pointer,
                    typename ft::iterator_traits<Iterator>::reference>
    {
    protected:
        Iterator current;
    public:
        typedef Iterator                                            iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::reference       reference;
        typedef typename iterator_traits<Iterator>::pointer         pointer;

        reverse_iterator();
        explicit reverse_iterator(Iterator x);
        template <class U> reverse_iterator(const reverse_iterator<U>& u);
        template <class U> reverse_iterator& operator=(const reverse_iterator<U>& u);
        Iterator base() const;
        reference operator*() const;
        pointer   operator->() const;
        reverse_iterator& operator++();
        reverse_iterator  operator++(int);
        reverse_iterator& operator--();
        reverse_iterator  operator--(int);
        reverse_iterator  operator+ (difference_type n) const;
        reverse_iterator& operator+=(difference_type n);
        reverse_iterator  operator- (difference_type n) const;
        reverse_iterator& operator-=(difference_type n);
        reference         operator[](difference_type n) const;
    };

    template <class Iterator1, class Iterator2>
    bool    operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    bool    operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    bool    operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    bool    operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    bool    operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    bool    operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);
/*
    template <class Iterator1, class Iterator2>
    operator-(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
    -> decltype(__y.base() - __x.base());   // constexpr in C++17
*/
    template <class Iterator>
    reverse_iterator<Iterator>
    operator+(typename reverse_iterator<Iterator>::difference_type n,
              const reverse_iterator<Iterator>& x);

    template <class Iterator>
    reverse_iterator<Iterator> make_reverse_iterator(Iterator i);

    template <bool, class _Tp = void> struct enable_if {};
    template <class _Tp> struct enable_if<true, _Tp> {typedef _Tp type;};

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

    template<class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
    distance (InputIterator first, InputIterator last) {
        return __distance(first, last, typename iterator_traits<InputIterator>::iterator_category());
    }
}
#endif //UNTITLED1_ITERATER_HPP
