class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0, y = 0, dir = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        int cnt = 0;
        vector<int> result;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(cnt < total) {
            result.push_back(matrix[x][y]);
            visited[x][y] = true;
            cnt++;

            if(dir == 0) {
                if(y == n - 1 || visited[x][y + 1]) {
                    dir = 1;
                    x++;
                } else {
                    y++;
                }
            } else if(dir == 1) {
                if(x == m - 1 || visited[x + 1][y]) {
                    dir = 2;
                    y--;
                } else {
                    x++;
                }
            } else if(dir == 2) {
                if(y == 0 || visited[x][y - 1]) {
                    dir = 3;
                    x--;
                } else {
                    y--;
                }
            } else if(dir == 3) {
                if(x == 0 || visited[x - 1][y]) {
                    dir = 0;
                    y++;
                } else {
                    x--;
                }
            }
        }

        return result;
    }
};