#include <iostream>

bool CanEscape(bool grid[], int w, int h, int x, int y)
{
  if (x<0 || x==w) return false;
  if (grid[x+y*w]) return false;
  if (y == h-1) return true;
  return (   CanEscape(grid,w, h, x, y+1)
          || CanEscape(grid, w, h, x-1, y)
          || CanEscape(grid, w, h, x+1, y)
          );
}

int main()
{
  int w, h;
  std::cin >> w >> h;
  bool grid[w*h];
  int x, y;
  for (int i=0; i<h; i++) {
    std::string row;
    std::cin >> row;
    for (int j=0; j<w; j++) {
      if (row[j] == 'R') grid[i+j*w] = true;
      else if (row[j] == 'Y') {
        x = j;
        y = i;
      }
    }
  }
  if (CanEscape(grid, w, h, x, y)) std::cout << "YES";
  else std::cout << "NO";
}
