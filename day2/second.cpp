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

class Sum
{
	int sch = 0;
	int sum = 0;

public:
	void operator()(int value)
	{
		sum += value;
		++sch;
	}

	operator int() const { if(sch != 0) return sum / sch; else return 0; }
};

int main()
{
	std::array<int, 12> a;

	std::cout << "Введите массив " << std::endl;
	for_each(a.begin(), a.end(), [](int& v){ std::cin >> v; });

	auto s = for_each(a.begin(), a.end(), Sum());

	a[5] = s;

	for_each(a.begin(), a.end(), [](int v){ std::cout << v << " "; });
	std::cout << '\n';

	return 0;
}
