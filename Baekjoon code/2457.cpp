#include <bits/stdc++.h>
using namespace std;

int N, m1, d1, m2, d2, curDay, endDay, ans;
pair<int, int> arr[100000];

int calcDay(int month, int day);
bool compare(pair<int, int> a, pair<int, int> b);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> m1 >> d1 >> m2 >> d2;
    arr[i] = {calcDay(m1, d1), calcDay(m2, d2)};
  }
  sort(arr, arr + N, compare);

  curDay = 60;
  for (int i = 0; i < N;) {
    if (arr[i].first > curDay) break;
    endDay = 0;
    while (i < N && arr[i].first <= curDay) {
      if (arr[i].second > endDay) endDay = arr[i].second;
      i++;
    }
    if (endDay == 0) {
      ans = 0;
      break;
    }
    curDay = endDay;
    ans++;
    if (curDay >= 335) break;
  }
  if (curDay < 335) ans = 0;
  cout << ans;

  return 0;
}

int calcDay(int month, int day) {
  int arr[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
  return arr[month - 1] + day;
}

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}