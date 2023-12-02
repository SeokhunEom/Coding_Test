#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
  int answer = 0;
  vector<string> avail;
  vector<string> s;
  s.push_back("aya");
  s.push_back("ye");
  s.push_back("woo");
  s.push_back("ma");

  for (int i = 0; i < 4; i++) {
    avail.push_back(s[i]);
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      avail.push_back(s[i] + s[j]);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (i == j || i == k || j == k) continue;
        avail.push_back(s[i] + s[j] + s[k]);
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
          if (i == j || i == k || i == l || j == k || j == l || k == l)
            continue;
          avail.push_back(s[i] + s[j] + s[k] + s[l]);
        }
      }
    }
  }

  for (string s1 : babbling) {
    for (string s2 : avail) {
      if (s1 == s2) answer++;
    }
  }

  return answer;
}