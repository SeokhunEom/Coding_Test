#include <climits>
#include <iostream>
using namespace std;

int N, mp, mf, ms, mv, ans1 = INT_MAX, ans2, sum_p, sum_f, sum_s, sum_v, sum_c;
int arrp[16], arrf[16], arrs[16], arrv[16], arrc[16];

bool is_lex_smaller(int a, int b) {
  int idx_a = 0, idx_b = 0;
  while (idx_a < N || idx_b < N) {
    while (idx_a < N && !(a & (1 << idx_a))) idx_a++;
    while (idx_b < N && !(b & (1 << idx_b))) idx_b++;

    if (idx_a == N && idx_b == N) {
      return false;
    }
    if (idx_a == N) {
      return true;
    }
    if (idx_b == N) {
      return false;
    }

    if (idx_a < idx_b) {
      return true;
    } else if (idx_a > idx_b) {
      return false;
    } else {
      idx_a++;
      idx_b++;
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> mp >> mf >> ms >> mv;
  for (int i = 0; i < N; i++) {
    cin >> arrp[i] >> arrf[i] >> arrs[i] >> arrv[i] >> arrc[i];
  }

  for (int i = 1; i < (1 << N); i++) {
    sum_p = 0;
    sum_f = 0;
    sum_s = 0;
    sum_v = 0;
    sum_c = 0;

    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        sum_p += arrp[j];
        sum_f += arrf[j];
        sum_s += arrs[j];
        sum_v += arrv[j];
        sum_c += arrc[j];
      }
    }

    if (sum_p >= mp && sum_f >= mf && sum_s >= ms && sum_v >= mv) {
      if (ans1 > sum_c) {
        ans1 = sum_c;
        ans2 = i;
      } else if (ans1 == sum_c) {
        if (is_lex_smaller(i, ans2)) {
          ans2 = i;
        }
      }
    }
  }

  if (ans1 == INT_MAX) {
    cout << -1;
  } else {
    cout << ans1 << '\n';
    for (int i = 0; i < N; i++) {
      if (ans2 & (1 << i)) {
        cout << i + 1 << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}