#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  string str;
  int len;

  cin >> str;
  len = str.length();
  for (int i = 0; i < len; i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] += 32;
    }
    else
    {
      str[i] -= 32;
    }
  }
  cout << str;
  return 0;
}