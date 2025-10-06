class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        vector<int> output;

        // 전부 음수나 양수인 경우는 예외처리.
        if (nums[nums.size() - 1] <= 0) {
            for (int i = nums.size() - 1; i >= 0; i--) {
                output.push_back(nums[i] * nums[i]);
            }
            return output;
        }
        if (nums[0] >= 0) {
            for (int i = 0; i < nums.size(); i++) {
                output.push_back(nums[i] * nums[i]);
            }
            return output;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && nums[i + 1] >= 0) {
                if (abs(nums[i]) < abs(nums[i + 1])) {
                    leftIndex = i;
                } else {
                    leftIndex = i + 1;
                }
                rightIndex = leftIndex + 1;
                break;
            } 
        }

        while (leftIndex >= 0 && rightIndex < nums.size()) {
            if (abs(nums[leftIndex]) < abs(nums[rightIndex])) {
                output.push_back(nums[leftIndex] * nums[leftIndex]);
                leftIndex--;
            } else {
                output.push_back(nums[rightIndex] * nums[rightIndex]);
                rightIndex++;
            }
        }
        while (leftIndex >= 0) {
            output.push_back(nums[leftIndex] * nums[leftIndex]);
            leftIndex--;
        }
        while (rightIndex < nums.size()) {
            output.push_back(nums[rightIndex] * nums[rightIndex]);
            rightIndex++;
        }

        return output;
    }
};