#include <iostream>
#include <array>

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for(; first != last; ++first)
	{
		f(*first);
	}
	return f;
}

int main()
{
	std::cout << "Введите элементы массива" << std::endl;

	std::array<int, 14> a;

	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	for_each(a.begin(), a.end(), [](int v){ std:: cout << v << " "; });

	return 0;
}
