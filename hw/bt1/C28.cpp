#include <iostream>

int main()
{
	std::cout << "12 midnight\n";
	for (int i = 0; i < 23; i++) {
		std::cout << 1 + i % 12;
		if (i < 11) {
			std::cout << "am\n";
		}
		if (i > 11) {
			std::cout << "pm\n";
		}
		if (i == 11) {
			std::cout << " noon\n";
		}
	}
}