#include <iostream>

int main()
{
  int n;
  std::cin >> n;
  for (int i=n-1; i>=0; i--) {
    for (int t=0; t<n-i-1; t++) std::cout << " ";
    for (int t=0; t<1+i*2; t++) std::cout << "*";
    for (int t=0; t<n-i-1; t++) std::cout << " ";
    std::cout << "\n";
  }
}

