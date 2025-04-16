#include <iostream>
#include <vector>
using namespace std;

int N, S, l, r, ans, t;
bool flag;
vector<int> v;
int cnt[10];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S;
    v.push_back(S);
  }

  while (l <= r) {
    if (r >= N) {
      break;
    }

    if (!flag) {
      cnt[v[r]]++;
      if (cnt[v[r]] == 1) {
        t++;
      }
    } else {
      flag = false;
    }

    if (t <= 2) {
      ans = ans > (r - l + 1) ? ans : (r - l + 1);
      r++;
    } else {
      cnt[v[l]]--;
      if (!cnt[v[l]]) {
        t--;
      }
      l++;
      flag = true;
    }
  }

  cout << ans;

  return 0;
}