#include <bits/stdc++.h>

using namespace std;

int T, N;
string s;
string mbti[16] = {"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP",
                   "INFP", "INTP", "ESTP", "ESFP", "ENFP", "ENTP",
                   "ESTJ", "ESFJ", "ENFJ", "ENTJ"};
int dist[16][16];
map<string, int> mapper;

void init(void);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();

  cin >> T;
  for (int t = 0; t < T; t++) {
    vector<string> v;
    int ans = INT_MAX;
    cin >> N;

    for (int i = 0; i < N; i++) {
      cin >> s;
      v.push_back(s);
    }

    if (N > 32) {
      cout << 0 << '\n';
      continue;
    }

    for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
        for (int k = j + 1; k < v.size(); k++) {
          ans = min(ans, dist[mapper[v[i]]][mapper[v[j]]] +
                             dist[mapper[v[j]]][mapper[v[k]]] +
                             dist[mapper[v[k]]][mapper[v[i]]]);
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

void init(void) {
  for (int i = 0; i < 16; i++) mapper[mbti[i]] = i;

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        if (mbti[i][k] != mbti[j][k]) cnt++;
      }
      dist[i][j] = cnt;
    }
  }
}