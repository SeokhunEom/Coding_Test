#include <iostream>
using namespace std;

int N, M, a, b;
string s;
char arr[50][50];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      arr[i][j] = s[j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == 'X') {
        a++;
        break;
      }
    }
  }
  for (int j = 0; j < M; j++) {
    for (int i = 0; i < N; i++) {
      if (arr[i][j] == 'X') {
        b++;
        break;
      }
    }
  }

  cout << max(N - a, M - b);

  return 0;
}