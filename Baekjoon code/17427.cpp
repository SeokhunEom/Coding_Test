#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long n, ans = 0;

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    ans += (n / i) * i;
  }
  cout << ans;
}