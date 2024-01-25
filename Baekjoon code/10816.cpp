#include <bits/stdc++.h>
using namespace std;

int N, M, num;
int arr[500000];
map<int, int> m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    m[num]++;
  }
  cin >> M;
  for (int i = 0; i < M; i++) cin >> arr[i];
  for (int i = 0; i < M; i++) cout << m[arr[i]] << ' ';

  return 0;
}
