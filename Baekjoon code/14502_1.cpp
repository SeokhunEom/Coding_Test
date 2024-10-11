#include <iostream>
#include <queue>
using namespace std;

int N, M, ans;
int board[8][8];
int new_board[8][8];
int arr[3];
int visited[8][8];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void func1(void);
void func2(void);
void func3(void);

void func1(int cur, int depth) {
    if(depth == 3) {
        func2();
        return;
    }
    if(cur >= N * M) return;
    arr[depth] = cur;
    func1(cur + 1, depth + 1);
    func1(cur + 1, depth);
}

void func2(void) {
    int x1 = arr[0] / M;
    int y1 = arr[0] % M;
    int x2 = arr[1] / M;
    int y2 = arr[1] % M;
    int x3 = arr[2] / M;
    int y3 = arr[2] % M;
    if(board[x1][y1] != 0 || board[x2][y2] != 0 || board[x3][y3] != 0) return;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            new_board[i][j] = board[i][j];
        }
    }
    new_board[x1][y1] = 1;
    new_board[x2][y2] = 1;
    new_board[x3][y3] = 1;
    func3();
}

void func3(void) {
    queue<pair<int, int>> q;
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = 0;
            if(new_board[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(new_board[nx][ny] == 1 || visited[nx][ny] == 1) continue;
            new_board[nx][ny] = 2;
            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(new_board[i][j] == 0) cnt++;
        }
    }

    ans = max(ans, cnt);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    func1(0, 0);
    cout << ans;

  return 0;
}