#include <bits/stdc++.h>
using namespace std;

int arr[21];

void reverse(int, int);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  for (int i = 0; i < 21; i++) {
    arr[i] = i;
  }

  for (int i = 0; i < 10; i++) {
    cin >> a >> b;
    if(a != b)
      reverse(a, b);
  }

  for (int i = 1; i < 21; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}

void reverse(int a, int b) {
  int temp[b - a + 1];
  for(int i = 0; i <= b - a; i++)
    temp[i] = arr[b - i];
  for(int i = a; i <= b; i++)
    arr[i] = temp[i - a];
}