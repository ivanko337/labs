#include <iostream>
#include <array>

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for(; first != last; ++first)
		f(*first);
	return f;
}

class Functor
{
public:
	int even = 0;
	int odder = 0;

	void operator()(int v)
	{
		if (v % 2 == 0) ++even;
		else ++odder;
	}
};

int main()
{
	std::array<int, 20> a;
	std::cout << "введи массив" << std::endl;
	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	auto f = for_each(a.begin(), a.end(), Functor());

	std::cout << "\nчётных: " << f.even << std::endl << "нечётных: " << f.odder << std::endl;

	return 0;
}
