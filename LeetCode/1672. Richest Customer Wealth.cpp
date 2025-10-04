class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = accounts[0][0];
        for (vector<int>& account: accounts) {
            int total = 0;
            for (int money: account) {
                total += money;
            }
            if (total > maxWealth) {
                maxWealth = total;
            }
        }
        return maxWealth;
    }
};