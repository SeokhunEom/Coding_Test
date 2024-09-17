#include <iostream>
using namespace std;

int A, B, C, in1, in2, in3, out1, out2, out3, ans;
int arr[101];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;
  cin >> in1 >> out1 >> in2 >> out2 >> in3 >> out3;

  for(int i = in1; i < out1; i++) {
    arr[i]++;
  }
  for(int i = in2; i < out2; i++) {
    arr[i]++;
  }
  for(int i = in3; i < out3; i++) {
    arr[i]++;
  }
  
  for(int i = 1; i <= 100; i++) {
    if(arr[i] == 1) {
      ans += A;
    } else if(arr[i] == 2) {
      ans += B * 2;
    } else if(arr[i] == 3) {
      ans += C * 3;
    }
  }

  cout << ans;

  return 0;
}