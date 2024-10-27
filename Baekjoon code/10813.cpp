#include <iostream>
using namespace std;

int N, M, a, b, c;
int arr[101];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 1; i < 101; i++) {
    arr[i] = i;
  }

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
  }
  for (int i = 1; i <= N; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}