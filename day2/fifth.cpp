#include <iostream>
#include <array>
#include <iterator>
#include <utility>

template<class ForwardIt, class Compare>
std::pair<ForwardIt, ForwardIt>
	minmax_element(ForwardIt first, ForwardIt last, Compare comp)
{
	std::pair<ForwardIt, ForwardIt> result(first, first);

	if (first == last) return result;
	if (++first == last) return result;

	if (comp(*first, *result.first))
	{
		result.first = first;
	}
	else
	{
		result.second = first;
	}

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
				if (!(comp(*first, *result.second))) result.second = first;
			}
		}
	}
	return result;
}

template<class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for(; first != last; ++first)
		f(*first);
	return f;
}

int main()
{
	std::array<int, 9> a;
	std::cout << "Введи массив " << std::endl;

	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	auto minmax = minmax_element(a.begin(), a.end(), [](int a, int b){ return a < b; });

	swap(*minmax.first, *minmax.second);

	std::cout << "\nитоговый массив: " << std::endl;
	for_each(a.begin(), a.end(), [](int v){ std::cout << v << std::endl; });

	return 0;
}
