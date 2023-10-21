#include <bits/stdc++.h>
using namespace std;

char arr[50][50];
int n, maxCandy;
string s;

void calcMaxCandy();
void swap(int a1, int b1, int a2, int b2);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      arr[i][j] = s[j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != 0 && arr[i][j] != arr[i - 1][j]) {
        swap(i, j, i - 1, j);
        calcMaxCandy();
        swap(i, j, i - 1, j);
      }
      if (j != n - 1 && arr[i][j] != arr[i][j + 1]) {
        swap(i, j, i, j + 1);
        calcMaxCandy();
        swap(i, j, i, j + 1);
      }
      if (i != n - 1 && arr[i][j] != arr[i + 1][j]) {
        swap(i, j, i + 1, j);
        calcMaxCandy();
        swap(i, j, i + 1, j);
      }
      if (j != 0 && arr[i][j] != arr[i][j - 1]) {
        swap(i, j, i, j - 1);
        calcMaxCandy();
        swap(i, j, i, j - 1);
      }
    }
  }

  cout << maxCandy;

  return 0;
}

void calcMaxCandy() {
  int before, maxLen;

  for (int i = 0; i < n; i++) {
    before = 0;
    for (int j = 0; j < n; j++) {
      if (before != arr[i][j]) {
        before = arr[i][j];
        maxLen = 1;
      } else {
        maxLen++;
        if (maxLen > maxCandy) {
          maxCandy = maxLen;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    before = 0;
    for (int j = 0; j < n; j++) {
      if (before != arr[j][i]) {
        before = arr[j][i];
        maxLen = 1;
      } else {
        maxLen++;
        if (maxLen > maxCandy) {
          maxCandy = maxLen;
        }
      }
    }
  }
}

void swap(int a1, int b1, int a2, int b2) {
  char temp;

  temp = arr[a1][b1];
  arr[a1][b1] = arr[a2][b2];
  arr[a2][b2] = temp;
}