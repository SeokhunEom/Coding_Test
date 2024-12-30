#include <iostream>
using namespace std;

int P, N, ans;
int arr[20];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> P;
  for (int p = 0; p < P; p++) {
    cin >> N;
    for (int i = 0; i < 20; i++) {
      cin >> arr[i];
    }
    ans = 0;

    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < i; j++) {
        if (arr[i] < arr[j]) {
          ans++;
        }
      }
    }

    cout << N << " " << ans << "\n";
  }

  return 0;
}