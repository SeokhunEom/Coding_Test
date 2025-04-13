#include <iostream>
using namespace std;

string s1, s2, s3;
int num;
bool flag = true;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s1 >> s2 >> s3;
  if (s1[0] != 'F' && s1[0] != 'B') {
    num = stoi(s1);
    num += 3;
  } else if (s2[0] != 'F' && s2[0] != 'B') {
    num = stoi(s2);
    num += 2;
  } else {
    num = stoi(s3);
    num += 1;
  }

  if (num % 3 == 0) {
    cout << "Fizz";
    flag = false;
  }
  if (num % 5 == 0) {
    cout << "Buzz";
    flag = false;
  }
  if (flag) {
    cout << num;
  }

  return 0;
}