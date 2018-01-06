#include <iostream>
#include <array>
#include <utility>
#include <algorithm>

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for (; first != last; ++first)
		f(*first);
	return f;
}

template<class ForwardIt, class Compare>
std::pair<ForwardIt, ForwardIt>
	minmax_element(ForwardIt first, ForwardIt last, Compare comp)
{
	std::pair<ForwardIt, ForwardIt> result(first, first);

	if (first == last) return result;
	if(++first == last) return result;

	if (comp(*first, *result.first)) result.first = first;
	else result.second = first;
	while (++first != last)
	{
		ForwardIt i = first;
		if (++first == last)
		{
			if (comp(*i, *result.first)) result.first = i;
			else if (!(comp(*i, *result.second))) result.second = i;
			break;
		}
		else
		{
			if (comp(*first, *i))
			{
				if (comp(*first, *result.first)) result.first = first;
				if (!(comp(*i, *result.second))) result.second = i;
			}
			else
			{
				if (comp(*i, *result.first)) result.first = i;
				if(!(comp(*first, *result.second))) result.second = first;
			}
		}
	}
	return result;
}

int main()
{
	std::array<int, 4> a;
	std::cout << "введите массив: " << std::endl;
	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	auto r = minmax_element(a.begin(), a.end(), [](int a, int b){ return a > b; });
	std::cout << '\n' << *r.first << '\n' << *r.second << std::endl;

	return 0;
}
