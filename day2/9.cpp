#include <iostream>
#include <utility>
#include <vector>

int sredn = 0;

template<class InputIt, class UnaryFunc>
UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
	for(; first != last; ++first)
		f(*first);
	return f;
}

template<class T, class Schetchik>
class Sredn
{
public:
	T sum = 0;
	Schetchik sch = 0;

	void operator()(T v)
	{
		sum += v;
		++sch;
	}

	operator int() const
	{
		if (sch != 0) return sum / sch;
		else return 0;
	}
};

template<class T>
class NewArr
{
public:
	std::vector<T> res;

	void operator()(int v)
	{
		res.push_back(v);
	}
};

int main()
{
	std::vector<int> a{ 1, 54, 34, 2, 43, 5, 7, 237, 153, 78, 935648, 1123 };
	std::cout << "изначальный массив: " << std::endl;
	for_each(a.begin(), a.end(), [](int v){ std::cout << v << std::endl; });

	auto res = for_each(a.begin(), a.end(), Sredn<int, int>());
	sredn = res;
	std::cout << "\nсреднее: " << sredn << std::endl;

	for_each(a.begin(), a.end(), [](int& v){ v -= sredn; });

	auto gavno2 = for_each(a.begin(), a.end(), NewArr<int>());
	std::vector<int> itog = gavno2.res;

	std::cout << "\nИтоговый массив:  " << std::endl;
	for_each(itog.begin(), itog.end(), [](int v){ std::cout << v << std::endl; });

	return 0;
}
