#include <iostream>
#include <array>

int odder_sum = 0;

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for(; first != last; ++first)
		f(*first);
	return f;
}

template<class T>
class OdderSum
{
public:
	T sum = 0;

	void operator()(T v)
	{
		if (v % 2 == 1)
		{
			sum += v;
			odder_sum = sum;
		}
	}
};

int main()
{
	std::array<int, 17> a;
	std::cout << "введи массив: " << std::endl;

	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	for_each(a.begin(), a.end(), OdderSum<int>());
	std::cout << "\nсумма нечётных элементов: " << odder_sum << std::endl;

	for_each(a.begin(), a.end(), [](int& v){ if (v % 3 == 0) v = odder_sum; });

	std::cout << "итоговый массив: " << std::endl;
	for_each(a.begin(), a.end(), [](int v){ std::cout << v << std::endl; });

	return 0;
}
