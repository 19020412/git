#include <iostream>

int main()
{
  int n;
  std::cin >> n;
  for (int i=0; i<n; i++) {
    int ii = 0;
    while (ii < i) {
        std::cout << " ";
        ii++;
    }
    while (ii < n) {
      std::cout << "*";
      ii++;
    }
    std::cout << std::endl;
  }
}
