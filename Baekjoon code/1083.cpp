#include <iostream>
using namespace std;

int N, S, start, idx;
int arr[50];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  cin >> S;

  while (start < N && S > 0) {
    idx = start;
    for (int i = start; i <= min(N - 1, start + S); i++) {
      if (arr[i] > arr[idx]) {
        idx = i;
      }
    }
    for (int i = idx; i > start; i--) {
      if (S == 0) {
        break;
      }
      swap(arr[i], arr[i - 1]);
      S--;
    }
    start++;
  }

  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}