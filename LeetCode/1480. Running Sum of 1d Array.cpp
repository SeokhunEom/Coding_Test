class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSums;
        runningSums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            runningSums.push_back(runningSums[i - 1] + nums[i]);
        }
        return runningSums;
    }
};