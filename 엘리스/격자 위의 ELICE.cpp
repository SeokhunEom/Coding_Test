#include <bits/stdc++.h>
using namespace std;

int N, a, b, ans1, ans2, temp;
int maze[1001][1001];
int elice[5][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct State {
  int x, y, cost;
  State(int x, int y, int cost) : x(x), y(y), cost(cost){};
  bool operator<(const State &state) const { return cost > state.cost; }
};

int calc(int ax, int ay, int bx, int by) {
  int costTable[1001][1001];
  priority_queue<State> q;

  q.push(State(ax, ay, 0));
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      costTable[i][j] = INT_MAX;
    }
  }
  costTable[ax][ay] = 0;

  while (true) {
    int cur_x = q.top().x;
    int cur_y = q.top().y;
    int cur_cost = q.top().cost;
    q.pop();

    if (cur_x == bx && cur_y == by) return cur_cost;

    for (int dir = 0; dir < 4; dir++) {
      int next_x = cur_x + dx[dir];
      int next_y = cur_y + dy[dir];
      if (!next_x || next_x > N || !next_y || next_y > N) continue;

      int temp_cost = cur_cost + maze[next_x][next_y] + maze[cur_x][cur_y];
      if (temp_cost < costTable[next_x][next_y]) {
        costTable[next_x][next_y] = temp_cost;
        q.push(State(next_x, next_y, temp_cost));
      }
    }
  }

  return INT_MAX;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> maze[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    cin >> elice[i][0] >> elice[i][1];
  }

  int temp = calc(elice[1][0], elice[1][1], elice[2][0], elice[2][1]) +
             calc(elice[2][0], elice[2][1], elice[3][0], elice[3][1]);

  int ans1 = calc(1, 1, elice[0][0], elice[0][1]) +
             calc(elice[0][0], elice[0][1], elice[1][0], elice[1][1]) +
             calc(elice[3][0], elice[3][1], elice[4][0], elice[4][1]) + temp;

  int ans2 = calc(1, 1, elice[4][0], elice[4][1]) +
             calc(elice[4][0], elice[4][1], elice[1][0], elice[1][1]) +
             calc(elice[3][0], elice[3][1], elice[0][0], elice[0][1]) + temp;

  cout << min(ans1, ans2);

  return 0;
}