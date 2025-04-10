#include <iostream>
using namespace std;

int N, S, M, L, XL, XXL, XXXL, T, P, ans;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> S >> M >> L >> XL >> XXL >> XXXL;
  cin >> T >> P;

  ans += S / T;
  if (S % T != 0) {
    ans++;
  }
  ans += M / T;
  if (M % T != 0) {
    ans++;
  }
  ans += L / T;
  if (L % T != 0) {
    ans++;
  }
  ans += XL / T;
  if (XL % T != 0) {
    ans++;
  }
  ans += XXL / T;
  if (XXL % T != 0) {
    ans++;
  }
  ans += XXXL / T;
  if (XXXL % T != 0) {
    ans++;
  }

  cout << ans << "\n" << N / P << " " << N % P;

  return 0;
}