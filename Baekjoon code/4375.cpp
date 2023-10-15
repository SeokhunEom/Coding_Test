#include <iostream>

using namespace std;

int main()
{
  int n;
  while (cin >> n)
  {
    long long num = 1;
    int i;
    for (i = 1;; i++)
    {
      num = num % n;
      if (num == 0)
      {
        break;
      }
      num = (num * 10) % n + 1 % n;
    }
    cout << i << endl;
  }
  return 0;
}