#include <bits/stdc++.h>
using namespace std;

int N;
int arr[500000];
int cnt[8001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  int sum = 0;
  for (int i = 0; i < N; i++) sum += arr[i];
  int ret = round((double)sum / N);
  if (ret == -0) ret = 0;
  cout << ret << '\n';

  sort(arr, arr + N);
  cout << arr[N / 2] << '\n';

  for (int i = 0; i < N; i++) cnt[arr[i] + 4000]++;
  int max = 0;
  for (int i = 0; i < 8001; i++) {
    if (cnt[i] > max) max = cnt[i];
  }
  vector<int> v;
  for (int i = 0; i < 8001; i++) {
    if (cnt[i] == max) v.push_back(i - 4000);
  }
  if (v.size() > 1)
    cout << v[1] << '\n';
  else
    cout << v[0] << '\n';

  cout << arr[N - 1] - arr[0] << '\n';

  return 0;
}
