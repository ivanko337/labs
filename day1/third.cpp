#include <iostream>
#include <array>
#include <iterator>

int sredn = 0;

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for(; first != last; ++first)
		f(*first);
	return f;
}

template<class InputIt, class UnaryPred>
typename std::iterator_traits<InputIt>::difference_type
	count_if(InputIt first, InputIt last, UnaryPred f)
{
	typename std::iterator_traits<InputIt>::difference_type ret = 0;
	for(; first != last; ++first)
		if(f(*first))
			++ret;
	return ret;
}

class Sum
{
public:
	int sch = 0;
	int sum = 0;

	void operator()(int value)
	{
		sum += value;
		++sch;
	}

	operator int() const { if(sch != 0) return sum / sch; else return 0; }
};

int main()
{
	std::array<int, 11> a;

	std::cout << "vvedi massiv: " << std::endl;
	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	auto s = for_each(a.begin(), a.end(), Sum());

	sredn = s;

	std::cout << "Элементов больше среднего арифмитического: " << count_if(a.begin(), a.end(), [](int v){ return v > sredn; }) << std::endl;

	return 0;
}
