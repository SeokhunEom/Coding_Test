#include <bits/stdc++.h>
using namespace std;

int N, M, K, T, a, b, ans = 1, rest, temp;
bool flag = true;
pair<int, int> arr[300];
int timeline[302];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K >> T;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    arr[i] = {a, b};
  }

  for (int i = 0; i < M; i++) {
    for (int j = arr[i].first; j < arr[i].second; j++) {
      timeline[j]++;
    }
  }

  for (int start = 1; start < N; start++) {
    for (int end = start + ans; end < N + 1; end++) {
      flag = true;
      rest = K;
      temp = 0;

      for (int i = start; i <= end; i++) {
        if (timeline[i] + rest < T) {
          flag = false;
          break;
        }

        if (timeline[i] < T) {
          temp = max(temp, T - timeline[i]);
        } else {
          rest -= temp;
          temp = 0;
        }
      }

      if (flag) {
        ans = max(ans, end - start + 1);
      } else {
        break;
      }
    }
  }

  cout << ans;

  return 0;
}