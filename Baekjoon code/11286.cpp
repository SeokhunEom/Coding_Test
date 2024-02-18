#include <bits/stdc++.h>
using namespace std;

class compare {
 public:
  bool operator()(int a, int b) {
    if (abs(a) != abs(b)) return abs(a) > abs(b);
    return a > 0 && b < 0;
  }
};

int N, x;
priority_queue<int, vector<int>, compare> pq;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x;
    if (x == 0) {
      if (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
      } else
        cout << 0 << '\n';
    } else
      pq.push(x);
  }

  return 0;
}
