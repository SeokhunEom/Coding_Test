#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
  int answer = 0;

  int len = t.length() - p.length() + 1;
  int plen = p.length();
  for (int i = 0; i < len; i++) {
    string temp = t.substr(i, plen);
    bool flag = true;
    for (int j = 0; j < plen; j++) {
      if (p[j] < temp[j]) {
        flag = false;
        break;
      } else if (p[j] > temp[j]) {
        flag = true;
        break;
      }
    }
    if (flag == true) answer++;
  }

  return answer;
}