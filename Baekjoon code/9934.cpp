#include <iostream>
#include <vector>
using namespace std;

int K, N = 1;
int arr[1025];
vector<int> tree[10];

void func(int depth, int start, int end) {
  if (start >= end) return;
  int mid = (start + end) / 2;
  tree[depth].push_back(arr[mid]);
  func(depth + 1, start, mid);
  func(depth + 1, mid + 1, end);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> K;
  for (int i = 0; i < K; i++) N *= 2;
  for (int i = 0; i < N - 1; i++) cin >> arr[i];

  func(0, 0, N - 1);

  for (int i = 0; i < K; i++) {
    for (int j = 0; j < tree[i].size(); j++) {
      cout << tree[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}