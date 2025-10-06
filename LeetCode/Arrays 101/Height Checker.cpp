class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        int output = 0;
        sort(sortedHeights.begin(), sortedHeights.end());
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sortedHeights[i]) {
                output++;
            }
        }
        return output;
    }
};