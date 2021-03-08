#include <iostream>

int main()
{
	while (true) {
		int n;
		std::cin >> n;
		if (n == -1) {
			std::cout << "bye";
			break;
		}
		bool c = n % 5 != 0;
		std::cout << (c || n < 0 ? - 1 : n/5) << "\n";
	}
}