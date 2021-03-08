#include <iostream>
#include <math.h>

bool IsPrime(int x)
{
  if (x < 4) return true;
  for (int i=2; i <= std::sqrt(x); i++)
    if (x % i == 0) return false;
  return true;
}

int main()
{
  int x;
  std::cin >> x;
  std::cout << (IsPrime(x)? "true" : "false");
}
