//
// Created by gilee on 2022/04/20.
//

#ifndef UNTITLED1_ITERATER_HPP
#define UNTITLED1_ITERATER_HPP

#include <cstddef>
//#include <iterator>

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

        reverse_iterator() : current() {};
        explicit reverse_iterator(Iterator x) : current(x) {};
        template <class U> reverse_iterator(const reverse_iterator<U>& u) : current(u.base()) {};
        template <class U> reverse_iterator& operator=(const reverse_iterator<U>& u) {current = u.base(); return *this;};
        Iterator base() const{return current;};
        reference operator*() const {Iterator tmp = current; return *--tmp;};
        pointer   operator->() const {return *current;};
        reverse_iterator& operator++() {--current; return *this;};
        reverse_iterator  operator++(int) {reverse_iterator tmp(*this); --current; return tmp;};
        reverse_iterator& operator--() {++current; return *this;};
        reverse_iterator  operator--(int) {reverse_iterator tmp(*this); ++current; return tmp;};
        reverse_iterator  operator+ (difference_type n) const {return reverse_iterator(current - n);};
        reverse_iterator& operator+=(difference_type n) {current -= n; return *this;};
        reverse_iterator  operator- (difference_type n) const {return reverse_iterator(current + n);};
        reverse_iterator& operator-=(difference_type n) {current += n; return *this;};
        reference         operator[](difference_type n) const {return *(*this + n);};
    };

    template <class Iterator1, class Iterator2>
    bool    operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
        return x.base() == y.base();
    };

    template <class Iterator1, class Iterator2>
    bool    operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
        return x.base() > y.base();
    };

    template <class Iterator1, class Iterator2>
    bool    operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
        return x.base() != y.base();
    };

    template <class Iterator1, class Iterator2>
    bool    operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
        return x.base() < y.base();
    };

    template <class Iterator1, class Iterator2>
    bool    operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
        return x.base() <= y.base();
    };

    template <class Iterator1, class Iterator2>
    bool    operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
        return x.base() >= y.base();
    };

    template <class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type
    operator-(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
        return y.base() - x.base();
    }
    template <class Iterator>
    reverse_iterator<Iterator>
    operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x) {
        return reverse_iterator<Iterator>(x.base() - n);
    };
/*
    template <class Iterator>
    reverse_iterator<Iterator> make_reverse_iterator(Iterator i);
*/
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

template <class _Tp> struct __libcpp_is_integral                     : public std::false_type {};
template <>          struct __libcpp_is_integral<bool>               : public std::true_type {};
template <>          struct __libcpp_is_integral<char>               : public std::true_type {};
template <>          struct __libcpp_is_integral<signed char>        : public std::true_type {};
template <>          struct __libcpp_is_integral<unsigned char>      : public std::true_type {};
template <>          struct __libcpp_is_integral<wchar_t>            : public std::true_type {};
template <>          struct __libcpp_is_integral<char16_t>           : public std::true_type {};
template <>          struct __libcpp_is_integral<char32_t>           : public std::true_type {};
template <>          struct __libcpp_is_integral<short>              : public std::true_type {};
template <>          struct __libcpp_is_integral<unsigned short>     : public std::true_type {};
template <>          struct __libcpp_is_integral<int>                : public std::true_type {};
template <>          struct __libcpp_is_integral<unsigned int>       : public std::true_type {};
template <>          struct __libcpp_is_integral<long>               : public std::true_type {};
template <>          struct __libcpp_is_integral<unsigned long>      : public std::true_type {};
template <>          struct __libcpp_is_integral<long long>          : public std::true_type {};
template <>          struct __libcpp_is_integral<unsigned long long> : public std::true_type {};
template <>          struct __libcpp_is_integral<__int128_t>         : public std::true_type {};
template <>          struct __libcpp_is_integral<__uint128_t>        : public std::true_type {};

template <class _Tp> struct remove_const                  {typedef _Tp type;};
template <class _Tp> struct remove_const<const _Tp>       {typedef _Tp type;};
template <class _Tp> struct remove_volatile               {typedef _Tp type;};
template <class _Tp> struct remove_volatile<volatile _Tp> {typedef _Tp type;};

template <class _Tp> struct remove_cv
{typedef typename remove_volatile<typename remove_const<_Tp>::type>::type type;};

template <class _Tp>
struct
is_integral : public __libcpp_is_integral<typename remove_cv<_Tp>::type> {};


template <class _Tp> struct remove_reference        {typedef _Tp type;};
template <class _Tp> struct remove_reference<_Tp&>  {typedef _Tp type;};

    template <class _Tp, _Tp __v>
    struct integral_constant
    {
        static const _Tp      value = __v;
        typedef _Tp               value_type;
        typedef integral_constant type;
        operator value_type() const _NOEXCEPT {return value;}
    };

    namespace is_convertible_imp
    {
        template <class _Tp> void  __test_convert(_Tp);

        template <class _From, class _To, class = void>
    struct __is_convertible_test : public std::false_type {};

        template <class _From, class _To>
        struct __is_convertible_test<_From, _To,
    decltype(is_convertible_imp::__test_convert<_To>(std::declval<_From>()))> : public std::true_type
        {};

        template <class _Tp, bool _IsArray =    std::is_array<_Tp>::value,
                bool _IsFunction           =    std::is_function<_Tp>::value,
                bool _IsVoid               =    std::is_void<_Tp>::value>
        struct __is_array_function_or_void                          {enum {value = 0};};
        template <class _Tp> struct __is_array_function_or_void<_Tp, true, false, false> {enum {value = 1};};
        template <class _Tp> struct __is_array_function_or_void<_Tp, false, true, false> {enum {value = 2};};
        template <class _Tp> struct __is_array_function_or_void<_Tp, false, false, true> {enum {value = 3};};
    }

    template <class _T1, class _T2,
            unsigned _T1_is_array_function_or_void = is_convertible_imp::__is_array_function_or_void<_T1>::value,
            unsigned _T2_is_array_function_or_void = is_convertible_imp::__is_array_function_or_void<_T2>::value>
    struct _is_convertible
            : public integral_constant<bool,
                    is_convertible_imp::__is_convertible_test<_T1, _T2>::value
            >
    {};

template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 0, 1> : public std::false_type {};
template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 1, 1> : public std::false_type {};
template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 2, 1> : public std::false_type {};
template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 3, 1> : public std::false_type {};

template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 0, 2> : public std::false_type {};
template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 1, 2> : public std::false_type {};
template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 2, 2> : public std::false_type {};
template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 3, 2> : public std::false_type {};

template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 0, 3> : public std::false_type {};
template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 1, 3> : public std::false_type {};
template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 2, 3> : public std::false_type {};
template <class _T1, class _T2> struct _is_convertible<_T1, _T2, 3, 3> : public std::true_type {};

template <class _Tp,
        unsigned = is_convertible_imp::__is_array_function_or_void<typename remove_reference<_Tp>::type>::value>
struct __is_convertible_check { static const size_t __v = 0; };

template <class _Tp>
struct __is_convertible_check<_Tp, 0>
{
    static const size_t __v = sizeof(_Tp);
};

template <class _T1, class _T2> struct is_convertible
        : public _is_convertible<_T1, _T2>
{
    static const size_t __complete_check1 = __is_convertible_check<_T1>::__v;
    static const size_t __complete_check2 = __is_convertible_check<_T2>::__v;
};
}
#endif //UNTITLED1_ITERATER_HPP
