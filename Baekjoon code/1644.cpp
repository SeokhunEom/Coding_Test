#include <bits/stdc++.h>
using namespace std;

int N, ans;
bool arr[4000001];
vector<int> prime;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  arr[0] = true;
  arr[1] = true;
  for (int i = 2; i <= N; i++) {
    if (arr[i]) continue;
    prime.push_back(i);
    for (int j = i * 2; j <= N; j += i) arr[j] = true;
  }

  int left = 0, right = 0, sum = 0;
  while (1) {
    if (sum >= N)
      sum -= prime[left++];
    else if (right == prime.size())
      break;
    else
      sum += prime[right++];

    if (sum == N) ans++;
  }

  cout << ans;

  return 0;
}
