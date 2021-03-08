#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  bool a[N];
  bool result = false;
  for (int i=0; i<N; i++) {
    int c;
    std::cin >> c;
    if (a[c] == 0) a[c] = 1;
    else result = true;
  }
  if (result) std::cout << "Yes";
  else std::cout << "No";
}
