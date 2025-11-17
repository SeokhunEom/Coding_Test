class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int size = nums.size();
        int maxNum = -1, secondMaxNum = -1, maxNumIndex = -1;
        
        for (int i = 0; i < size; i++) {
            if (nums[i] > maxNum) {
                secondMaxNum = maxNum;
                maxNum = nums[i];
                maxNumIndex = i;
            } else if (nums[i] > secondMaxNum) {
                secondMaxNum = nums[i];
            }
        }
        
        if (maxNum >= 2 * secondMaxNum) {
            return maxNumIndex;
        } else {
            return -1;
        }
    }
};