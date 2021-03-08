#include <iostream>

int main()
{
  while(true) {
    int n;
    std::cin >> n;
    if (n == -1) break;
    int a = (n>0 && n%5==0)? n/5 : -1;
    std::cout << a << '\n';
  }
  std::cout << "bye";
}
