#include <iostream>

int main()
{
  std::cout << 12 << " midnight\n";
  for (int i=1; i<24; i++) {
    if (i < 12) std::cout << i % 12 <<"am\n";
    else if (i > 12) std::cout << i % 12 << "pm\n";
    else std::cout << 12 << " noon\n";
  }
}
