class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int x = 0, y = 0;
        int m = mat.size();
        int n = mat[0].size();
        int total = m * n;
        vector<int> result;
        int cnt = 0;
        bool up = true;

        while(cnt < total) {
            result.push_back(mat[x][y]);
            cnt++;

            if(up) {
                if(y == n - 1) {
                    x++;
                    up = false;
                } else if(x == 0) {
                    y++;
                    up = false;
                } else {
                    x--;
                    y++;
                }
            } else {
                if(x == m - 1) {
                    y++;
                    up = true;
                } else if(y == 0) {
                    x++;
                    up = true;
                } else {
                    x++;
                    y--;
                }
            }
        }

        return result;
    }
};