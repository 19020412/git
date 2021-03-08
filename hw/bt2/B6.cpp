#include <iostream>

int main()
{
  int n;
  std::cin >> n;
  for (int i=0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      std::cout << 1+((i+j)%n) << " ";
    }
    std::cout << "\n";
  }
}
