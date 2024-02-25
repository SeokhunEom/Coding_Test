#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool vis[101];
vector<int> v;

int solution(vector<int> cards) {
  int answer = 0;

  for (int card : cards) {
    if (vis[card]) continue;
    int size = 0;
    queue<int> q;
    q.push(card);
    vis[card] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      if (vis[cards[cur - 1]]) break;
      size++;
      q.push(cards[cur - 1]);
      vis[cards[cur - 1]] = true;
    }
    v.push_back(size + 1);
  }

  sort(v.begin(), v.end(), greater<int>());
  answer = v.size() == 1 ? 0 : v[0] * v[1];

  return answer;
}