#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int vis[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<int> solution(vector<string> maps) {
  vector<int> answer;

  queue<pair<int, int>> q;
  int n = maps.size();
  int m = maps[0].length();
  int idx = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maps[i][j] != 'X' && vis[i][j] == 0) {
        q.push({i, j});
        vis[i][j] = 1;
        answer.push_back(maps[i][j] - '0');

        while (!q.empty()) {
          pair<int, int> cur = q.front();
          q.pop();
          int x = cur.first;
          int y = cur.second;
          for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 'X' || vis[nx][ny] == 1) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
            answer[idx] += maps[nx][ny] - '0';
          }
        }

        idx++;
      }
    }
  }
  sort(answer.begin(), answer.end());

  if (answer.size() == 0) answer.push_back(-1);

  return answer;
}