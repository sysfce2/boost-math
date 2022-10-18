//  (C) Copyright Matt Borland 2022.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_CONCEPTS_CONCEPTS_HPP
#define BOOST_MATH_CONCEPTS_CONCEPTS_HPP

#if (__cplusplus >= 202002L || _MSVC_LANG >= 202002L) && !defined(BOOST_MATH_DISABLE_CONCEPTS)
#if __has_include(<concepts>)

#include <utility>
#include <algorithm>
#include <concepts>
#include <functional>
#include <type_traits>
#include <limits>
#include <iterator>
#include <boost/math/tools/config.hpp>
#include <boost/math/policies/policy.hpp>

namespace boost::math::concepts {

namespace detail {

template <typename X, typename Y, typename Op>
struct op_valid_impl
{
    template <typename U, typename L, typename R>
    static constexpr auto test(int) -> decltype(std::declval<U>()(std::declval<L>(), std::declval<R>()),
                                                void(), std::true_type());

    template <typename U, typename L, typename R>
    static constexpr auto test(...) -> std::false_type;

    using type = decltype(test<Op, X, Y>(0));
};

template <typename X, typename Y, typename Op> 
using op_valid_t = typename op_valid_impl<X, Y, Op>::type;

template <typename X, typename Y, typename Op>
inline constexpr bool op_valid_v = op_valid_t<X, Y, Op>::value;

// Detector for class member functions
struct nonesuch 
{
    nonesuch(const nonesuch&) = delete;
    ~nonesuch() = delete;
    void operator=(const nonesuch&) = delete;
};

template <typename Default, typename AlwaysVoid, template<typename...> typename Op, typename... Args>
struct detector 
{
    using value_t = std::false_type;
    using type = Default;
};
 
template <typename Default, template<typename...> typename Op, typename... Args>
struct detector<Default, std::void_t<Op<Args...>>, Op, Args...> 
{
    using value_t = std::true_type;
    using type = Op<Args...>;
};

template <template<typename...> typename Op, typename... Args>
using is_detected = typename detector<nonesuch, void, Op, Args...>::value_t;
 
template <template<typename...> typename Op, typename... Args>
using detected_t = typename detector<nonesuch, void, Op, Args...>::type;

#define BOOST_MATH_HAS_MEMBER_FUNCTION(member)                                      \
template <typename T>                                                               \
using has_##member##_t = decltype(std::declval<T&>().member());                     \
                                                                                    \
template <typename T>                                                               \
inline constexpr bool has_##member##_v = is_detected<has_##member##_t, T>::value;       

BOOST_MATH_HAS_MEMBER_FUNCTION(begin)
BOOST_MATH_HAS_MEMBER_FUNCTION(end)

} // Namespace detail

template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename T>
concept Signed_integral = Integral<T> && std::is_signed_v<T>;

template <typename T>
concept Unsigned_integral = Integral<T> && std::is_unsigned_v<T>;

template <typename T>
concept Real = std::is_floating_point_v<T>;

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <typename T>
concept Signed_arithmetic = Arithmetic<T> && std::is_signed_v<T>;

template <typename T>
concept Unsigned_arithmetic = Arithmetic<T> && std::is_unsigned_v<T>;

template <typename T>
concept Arbitrary_unsigned_arithmetic_type = Unsigned_arithmetic<T> ||
                                             (detail::op_valid_v<T, T, std::equal_to<>> &&
                                              detail::op_valid_v<T, T, std::not_equal_to<>> &&
                                              detail::op_valid_v<T, T, std::greater<>> &&
                                              detail::op_valid_v<T, T, std::less<>> &&
                                              detail::op_valid_v<T, T, std::greater_equal<>> &&
                                              detail::op_valid_v<T, T, std::less_equal<>> &&
                                              detail::op_valid_v<T, T, std::plus<>> &&
                                              detail::op_valid_v<T, T, std::minus<>> &&
                                              detail::op_valid_v<T, T, std::multiplies<>> &&
                                              detail::op_valid_v<T, T, std::divides<>>);

template <typename T>
concept Arbitrary_signed_arithmetic_type = Signed_arithmetic<T> ||
                                           (Arbitrary_unsigned_arithmetic_type<T> &&
                                            (detail::op_valid_v<T, T, std::negate<>> ||
                                             std::numeric_limits<T>::is_signed));

template <typename T>
concept Arbitrary_arithmetic_type = Arbitrary_unsigned_arithmetic_type<T> ||
                                    Arbitrary_signed_arithmetic_type<T>;

template <typename T>
concept Aribitrary_unsigned_integer_type = Arbitrary_unsigned_arithmetic_type<T> &&
                                           std::numeric_limits<T>::is_integer;

template <typename T>
concept Aribitrary_signed_integer_type = Arbitrary_signed_arithmetic_type<T> &&
                                         std::numeric_limits<T>::is_integer;

template <typename T>
concept Aribitrary_integer_type = Aribitrary_unsigned_integer_type<T> ||
                                  Aribitrary_signed_integer_type<T>;

template <typename T>
concept Aribitrary_real_type = Arbitrary_arithmetic_type<T> &&
                               !std::numeric_limits<T>::is_integer;

template <typename T>
concept policy = boost::math::policies::is_policy<T>::value;

// Workaround for LIBCPP versions that have <concepts> but have not implemented concepts in <iterator>
#if defined(_LIBCPP_VERSION) && !defined(_LIBCPP___ITERATOR_CONCEPTS_H)

template <typename T>
concept forward_iterator = std::is_same_v<typename std::iterator_traits<T>::iterator_category(), std::forward_iterator_tag>;

template <typename T>
concept bidirectional_iterator = std::is_same_v<typename std::iterator_traits<T>::iterator_category(), std::bidirectional_iterator_tag>;

template <typename T>
concept random_access_iterator = std::is_same_v<typename std::iterator_traits<T>::iterator_category(), std::random_access_iterator_tag>;

#else

template <typename T>
concept forward_iterator = std::forward_iterator<T>;

template <typename T>
concept bidirectional_iterator = std::bidirectional_iterator<T>;

template <typename T>
concept random_access_iterator = std::random_access_iterator<T>;

#endif

template <typename T>
concept is_container = detail::has_begin_v<T> &&
                       detail::has_end_v<T>;

template <typename T>
concept random_access_container = is_container<T> &&
                                  boost::math::concepts::random_access_iterator<typename T::iterator>;

} // boost::math::concepts

#define BOOST_MATH_INTEGRAL boost::math::concepts::Integral
#define BOOST_MATH_SIGNED_INTEGRAL boost::math::concepts::Signed_integral
#define BOOST_MATH_UNSIGNED_INTEGRAL boost::math::concepts::Unsigned_integral
#define BOOST_MATH_REAL boost::math::concepts::Real
#define BOOST_MATH_ARITHMETIC boost::math::concepts::Arithmetic
#define BOOST_MATH_SIGNED_ARITHMETIC boost::math::concepts::Signed_arithmetic
#define BOOST_MATH_UNSIGNED_ARITHMETIC boost::math::concepts::Unsigned_arithmetic
#define BOOST_MATH_ARBITRARY_UNSIGNED_ARITHMETIC boost::math::concepts::Arbitrary_unsigned_arithmetic_type
#define BOOST_MATH_ARBITRARY_SIGNED_ARITHMETIC boost::math::concepts::Arbitrary_signed_arithmetic_type
#define BOOST_MATH_ARBITRARY_ARITHMETIC boost::math::concepts::Arbitrary_arithmetic_type
#define BOOST_MATH_ARBITRARY_UNSIGNED_INTEGER boost::math::concepts::Aribitrary_unsigned_integer_type
#define BOOST_MATH_ARBITRARY_SIGNED_INTEGER boost::math::concepts::Aribitrary_signed_integer_type
#define BOOST_MATH_ARBITRARY_INTEGER boost::math::concepts::Aribitrary_integer_type
#define BOOST_MATH_ARBITRARY_REAL boost::math::concepts::Aribitrary_real_type
#define BOOST_MATH_POLICY boost::math::concepts::policy
#define BOOST_MATH_CONTAINER boost::math::concepts::is_container
#define BOOST_MATH_RANDOM_ACCESS_CONTAINER boost::math::concepts::random_access_container
#define BOOST_MATH_REQUIRES(X, T) requires X<T>

// Workaround for LIBCPP versions that have <concepts> but have not implemented concepts in <iterator>
#if defined(_LIBCPP_VERSION) && !defined(_LIBCPP___ITERATOR_CONCEPTS_H)

#define BOOST_MATH_FORWARD_ITER boost::math::concepts::forward_iterator
#define BOOST_MATH_BIDIRECTIONAL_ITER boost::math::concepts::bidirectional_iterator
#define BOOST_MATH_RANDOM_ACCESS_ITER boost::math::concepts::random_access_iterator

#else

#define BOOST_MATH_FORWARD_ITER std::forward_iterator
#define BOOST_MATH_BIDIRECTIONAL_ITER std::bidirectional_iterator
#define BOOST_MATH_RANDOM_ACCESS_ITER std::random_access_iterator

#endif

#endif
#endif

#ifndef BOOST_MATH_INTEGRAL
#  define BOOST_MATH_INTEGRAL typename
#endif

#ifndef BOOST_MATH_SIGNED_INTEGRAL
#  define BOOST_MATH_SIGNED_INTEGRAL typename
#endif

#ifndef BOOST_MATH_UNSIGNED_INTEGRAL
#  define BOOST_MATH_UNSIGNED_INTEGRAL typename
#endif

#ifndef BOOST_MATH_REAL
#  define BOOST_MATH_REAL typename
#endif

#ifndef BOOST_MATH_ARITHMETIC
#  define BOOST_MATH_ARITHMETIC typename
#endif

#ifndef BOOST_MATH_SIGNED_ARITHMETIC
#  define BOOST_MATH_SIGNED_ARITHMETIC typename
#endif

#ifndef BOOST_MATH_UNSIGNED_ARITHMETIC
#  define BOOST_MATH_UNSIGNED_ARITHMETIC typename
#endif

#ifndef BOOST_MATH_ARBITRARY_UNSIGNED_ARITHMETIC
#  define BOOST_MATH_ARBITRARY_UNSIGNED_ARITHMETIC typename
#endif

#ifndef BOOST_MATH_ARBITRARY_SIGNED_ARITHMETIC
#  define BOOST_MATH_ARBITRARY_SIGNED_ARITHMETIC typename
#endif

#ifndef BOOST_MATH_ARBITRARY_ARITHMETIC
#  define BOOST_MATH_ARBITRARY_ARITHMETIC typename
#endif

#ifndef BOOST_MATH_ARBITRARY_UNSIGNED_INTEGER
#  define BOOST_MATH_ARBITRARY_UNSIGNED_INTEGER typename
#endif

#ifndef BOOST_MATH_ARBITRARY_SIGNED_INTEGER
#  define BOOST_MATH_ARBITRARY_SIGNED_INTEGER typename
#endif

#ifndef BOOST_MATH_ARBITRARY_INTEGER
#  define BOOST_MATH_ARBITRARY_INTEGER typename
#endif

#ifndef BOOST_MATH_ARBITRARY_REAL
#  define BOOST_MATH_ARBITRARY_REAL typename
#endif

#ifndef BOOST_MATH_POLICY
#  define BOOST_MATH_POLICY typename
#endif

#ifndef BOOST_MATH_FORWARD_ITER
#  define BOOST_MATH_FORWARD_ITER typename
#endif

#ifndef BOOST_MATH_BIDIRECTIONAL_ITER
#  define BOOST_MATH_BIDIRECTIONAL_ITER typename
#endif

#ifndef BOOST_MATH_RANDOM_ACCESS_ITER
#  define BOOST_MATH_RANDOM_ACCESS_ITER typename
#endif

#ifndef BOOST_MATH_CONTAINER
#  define BOOST_MATH_CONTAINER typename
#endif

#ifndef BOOST_MATH_RANDOM_ACCESS_CONTAINER
#  define BOOST_MATH_RANDOM_ACCESS_CONTAINER typename
#endif

#ifndef BOOST_MATH_REQUIRES
#  define BOOST_MATH_REQUIRES(X, T)
#endif

#endif // BOOST_MATH_CONCEPTS_CONCEPTS_HPP
