#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int t;

bool compare(string s1, string s2) {
  if (s1[t] == s2[t]) return s1 < s2;
  return s1[t] < s2[t];
}

vector<string> solution(vector<string> strings, int n) {
  vector<string> answer = strings;

  t = n;
  sort(answer.begin(), answer.end(), compare);

  return answer;
}