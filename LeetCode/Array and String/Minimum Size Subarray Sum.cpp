class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int sum = 0;
        int minLength = INT_MAX;
        while (fast < nums.size()) {
            sum += nums[fast];
            while (sum >= target) {
                minLength = min(minLength, fast - slow + 1);
                sum -= nums[slow];
                slow++;
                }
            fast++;
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};