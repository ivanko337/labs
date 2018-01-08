#include <iostream>
#include <array>

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for(; first != last; ++first)
		f(*first);
	return f;
}

class Sum
{
public:
	int sum = 0;
	int sch = 0;

	void operator()(int v)
	{
		if ((v % 2 == 0) && (v > 0))
		{
			sum += v;
			++sch;
		}
	}
};

int main()
{
	std::array<int, 14> a;
	std::cout << "vvedi massiv" << std::endl;
	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	auto res = for_each(a.begin(), a.end(), Sum());

	std::cout << "sum: " << res.sum << std::endl << "count: " << res.sch << std::endl;

	return 0;
}
