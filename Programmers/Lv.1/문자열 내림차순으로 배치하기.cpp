#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";

  int len = s.length();
  char arr[len];
  for (int i = 0; i < len; i++) arr[i] = s[i];
  sort(arr, arr + len, greater<>());
  for (int i = 0; i < len; i++) answer += arr[i];

  return answer;
}