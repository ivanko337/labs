#include <iostream>
#include <array>

int main()
{
	std::array<int, 10> a;

	std::cout << a.end() - (a.begin() + 1) << std::endl;

	return 0;
}
