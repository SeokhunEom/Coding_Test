#include <bits/stdc++.h>
using namespace std;

int N;
char c1, c2, c3;
int l[27], r[27];

void preorder(int cur) {
  cout << (char)(cur + 'A' - 1);
  if (l[cur] != 0) preorder(l[cur]);
  if (r[cur] != 0) preorder(r[cur]);
}

void inorder(int cur) {
  if (l[cur] != 0) inorder(l[cur]);
  cout << (char)(cur + 'A' - 1);
  if (r[cur] != 0) inorder(r[cur]);
}

void postorder(int cur) {
  if (l[cur] != 0) postorder(l[cur]);
  if (r[cur] != 0) postorder(r[cur]);
  cout << (char)(cur + 'A' - 1);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> c1 >> c2 >> c3;
    if (c2 != '.') l[c1 - 'A' + 1] = c2 - 'A' + 1;
    if (c3 != '.') r[c1 - 'A' + 1] = c3 - 'A' + 1;
  }

  preorder(1);
  cout << '\n';
  inorder(1);
  cout << '\n';
  postorder(1);

  return 0;
}
