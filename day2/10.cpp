#include <iostream>
#include <array>

int sredn = 0;

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for(; first != last; ++first)
		f(*first);
	return f;
}

template<class T>
int abs(T val)
{
	return val < 0 ? -val : val;
}

template<class T, class Schetchik, class Itog>
class Sredn
{
public:
	T sum = 0;
	Schetchik sch = 0;
	Itog sredn;

	void operator()(T val)
	{
		if (val < 0)
		{
			++sch;
			sum += abs(val);
			sredn = sum / sch;
		}
	}
};

class Sum
{
public:
	int result = 0;

	void operator()(int val)
	{
		if (abs(val) > sredn)
			result += abs(val);
	}
};

int main()
{
	std::array<int, 17> a;
	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	auto s = for_each(a.begin(), a.end(), Sredn<int, int, int>());
	sredn = s.sredn;

	auto sum = for_each(a.begin(), a.end(), Sum());

	std::cout << "sum: " << sum.result << std::endl;

	return 0;
}

