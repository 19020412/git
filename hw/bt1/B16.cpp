#include <iostream>

int main()
{
  int x, y, z;
  std::cin >> x >> y >> z;
  if ( x == y && y == z )
    std::cout << "true";
  else std::cout << "false";
}
