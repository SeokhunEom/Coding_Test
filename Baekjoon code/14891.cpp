#include <bits/stdc++.h>
using namespace std;

int K, num, dir;
int gear[4][8];
int idx[4];
int rot[4];

void rotate(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 8; j++) {
      gear[i][j] = s[j] - '0';
    }
  }
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> num >> dir;
    for (int i = 0; i < 4; i++) rot[i] = 0;
    rotate();
  }
  cout << gear[0][idx[0]] + gear[1][idx[1]] * 2 + gear[2][idx[2]] * 4 +
              gear[3][idx[3]] * 8;

  return 0;
}

void rotate(void) {
  num--;
  rot[num] = dir;

  for (int i = num - 1; i >= 0; i--) {
    if (gear[i][(idx[i] + 2 + 8) % 8] != gear[i + 1][(idx[i + 1] - 2 + 8) % 8])
      rot[i] = -rot[i + 1];
    else
      break;
  }
  for (int i = num + 1; i < 4; i++) {
    if (gear[i][(idx[i] - 2 + 8) % 8] != gear[i - 1][(idx[i - 1] + 2 + 8) % 8])
      rot[i] = -rot[i - 1];
    else
      break;
  }

  for (int i = 0; i < 4; i++) idx[i] = (idx[i] - rot[i] + 8) % 8;
}