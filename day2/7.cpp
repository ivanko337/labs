#include <iostream>
#include <array>
#include <iterator>

double val = 0;

template<class InputIt, class UnaryPred>
typename std::iterator_traits<InputIt>::difference_type
	 count_if(InputIt first, InputIt last, UnaryPred p)
{
	typename std::iterator_traits<InputIt>::difference_type res = 0;
	for (; first != last; ++first)
		if (p(*first))
			++res;
	return res;
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
	std::array<double, 7> a{ 15.2, 87.6, 78.3, 12.8, 45.3, 789789.21, 52.9 };
	val = *a.begin();

	auto res =  count_if(a.begin(), a.end(), [](double v){ return v > val; });

	std::cout << "массив: ";
	for_each(a.begin(), a.end(), [](double v){ std::cout << v << " "; });
	std:: cout << '\n';
	std::cout << "Элементов больше первого: " << res << std::endl;

	return 0;
}
