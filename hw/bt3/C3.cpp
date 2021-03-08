#include <iostream>

bool IsN(int a)
{
    int n = 0;
    for (int c = a; c > 0; c /= 10)
        n++;
    char* ar = new char[n];
    for (int i = 0; i < n; i++) {
        ar[i] = a % 10;
        a /= 10;
    }
    for (int i = 0; i < n / 2; i++) {
        if (ar[i] != ar[n-i-1]) return false;
    }
    delete(ar);
    return true;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    int c = 0;
    for (int i = a; i <= b; i++) {
        if (IsN(i)) c++;
    }
    std::cout << c;
}
