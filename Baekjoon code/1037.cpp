#include <iostream>

using namespace std;

int main(void)
{
  int n, min, max, t;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> t;
    if (i == 0)
    {
      min = t;
      max = t;
    }
    if (min > t)
    {
      min = t;
    }
    if (max < t)
    {
      max = t;
    }
  }
  cout << min * max;

  return 0;
}