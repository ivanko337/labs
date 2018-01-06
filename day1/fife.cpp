#include <iostream>
#include <array>
#include <functional>
#include <utility>
#include <iterator>

template<class ForwarsIt>
std::pair<ForwardIt, ForwardIt>
	minmax_element(ForwardIt first, ForwardIt last)
{
	typedef typename std::iterator_traits<ForwardIt>::value_type value_t;
	return std::minmax_element(first, last, std::less<value_t>);
}
