#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";

  map<string, int> m;
  for (string s : participant) {
    if (m.find(s) != m.end()) {
      m[s]++;
    } else {
      m.insert({s, 1});
    }
  }
  for (string s : completion) {
    m[s]--;
  }
  for (string s : participant) {
    if (m[s] > 0) {
      answer = s;
      break;
    }
  }

  return answer;
}