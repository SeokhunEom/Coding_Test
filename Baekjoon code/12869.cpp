#include <algorithm>
#include <iostream>
using namespace std;

int N, ans = 10000;
int arr[3];
int HP[61][61][61];

void calculate(int scv1, int scv2, int scv3, int num) {
  if (scv1 <= 0 && scv2 <= 0 && scv3 <= 0) {
    ans = min(ans, num);
    return;
  }
  if (scv1 < 0) scv1 = 0;
  if (scv2 < 0) scv2 = 0;
  if (scv3 < 0) scv3 = 0;

  if (HP[scv1][scv2][scv3] <= num && HP[scv1][scv2][scv3] != 0) return;

  HP[scv1][scv2][scv3] = num;
  calculate(scv1 - 9, scv2 - 3, scv3 - 1, num + 1);
  calculate(scv1 - 9, scv2 - 1, scv3 - 3, num + 1);
  calculate(scv1 - 3, scv2 - 9, scv3 - 1, num + 1);
  calculate(scv1 - 3, scv2 - 1, scv3 - 9, num + 1);
  calculate(scv1 - 1, scv2 - 9, scv3 - 3, num + 1);
  calculate(scv1 - 1, scv2 - 3, scv3 - 9, num + 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  calculate(arr[0], arr[1], arr[2], 0);
  cout << ans;

  return 0;
}