#include <iostream>
using namespace std;

int N, B;
char arr[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
                'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
string ans;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> B;

  while (N > 0) {
    ans = arr[N % B] + ans;
    N /= B;
  }

  cout << ans;

  return 0;
}