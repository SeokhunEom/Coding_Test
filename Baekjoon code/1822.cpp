#include <bits/stdc++.h>
using namespace std;

int nA, nB, cnt;
int arrA[500000];
int arrB[500000];
int ans[500000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> nA >> nB;
  for (int i = 0; i < nA; i++) cin >> arrA[i];
  for (int i = 0; i < nB; i++) cin >> arrB[i];
  sort(arrA, arrA + nA);
  sort(arrB, arrB + nB);

  int idxA = 0, idxB = 0;
  while (idxA < nA && idxB < nB) {
    if (arrA[idxA] == arrB[idxB]) {
      idxA++;
      idxB++;
    } else if (arrA[idxA] < arrB[idxB]) {
      ans[cnt++] = arrA[idxA];
      idxA++;
    } else {
      idxB++;
    }
  }
  if (idxA < nA) {
    for (int i = idxA; i < nA; i++) ans[cnt++] = arrA[i];
  }

  cout << cnt << "\n";
  for (int i = 0; i < cnt; i++) cout << ans[i] << " ";

  return 0;
}
