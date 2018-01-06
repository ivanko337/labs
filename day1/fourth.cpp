#include <iostream>
#include <array>

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for(; first != last; ++first)
		f(*first);

	return f;
}

template<class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

class Max
{
public:
	int* max;

	void operator()(int& value)
	{
		if(value > *max)
			max = &value;
	}

	Max(int& first)
	{
		max = &first;
	}

};

int main()
{
	std::array<int, 10> a;

	std::cout << "vvedi massiv" << std::endl;
	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	auto max = for_each(a.begin() + 1, a.end(), Max(*a.begin()));

	swap(*a.begin(), *max.max);

	std::cout << "itogovi arr: " << std::endl;

	for_each(a.begin(), a.end(), [](int v){ std::cout << v << std::endl; });

	return 0;
}
