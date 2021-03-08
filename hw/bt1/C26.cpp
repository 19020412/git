#include <iostream>

int main()
{
  int n;
  std::cin >> n;

  int hi, lo = 429496729;
  double mid;
  for (int i=0; i<n; i++) {
    int a;
    std::cin >> a;
    mid += a;
    if (a > hi) hi = a;
    if (a < lo) lo = a;
  }
  mid /= n;
  std::cout << "Mean: " << mid << "\nMax: " << hi << "\nMin: " << lo;
}
