#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
  long long answer = 0;
  int arr[10] = {0};

  string s = to_string(n);
  for (char c : s) arr[c - '0']++;
  s = "";
  for (int i = 9; i > 0; i--) {
    for (int j = 0; j < arr[i]; j++) s += (i + '0');
  }
  answer = stoll(s);

  return answer;
}