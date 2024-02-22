#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> m;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int answer = 0;

  int len = want.size();
  for (int i = 0; i < len; i++) m[want[i]] = number[i];

  for (int i = 0; i <= discount.size() - 10; i++) {
    map<string, int> t;
    for (int j = i; j < i + 10; j++) t[discount[j]]++;
    bool flag = true;
    for (auto it : m) {
      if (t.find(it.first) == t.end()) {
        flag = false;
        break;
      } else if (t[it.first] != it.second) {
        flag = false;
        break;
      }
    }
    answer += flag == true ? 1 : 0;
  }

  return answer;
}