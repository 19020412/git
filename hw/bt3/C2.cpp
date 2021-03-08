#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;
  int n = s.length();
  for (int i = 0; i<n; i++) {
    if (s[i] != s[n-i-1]) {
      std::cout << "No";
      return 0;
    }
  }
  std::cout << "Yes";
}
