#include <iostream>

using namespace std;

int main(void) {
  int a;
  int c;
  cin >> a >> c;

  int b_square = c * c - a * a;  // 수정
  cout << b_square << endl;
  return 0;
}