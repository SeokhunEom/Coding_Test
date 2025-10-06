class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> output;
        for (int num : nums) {
            if (num % 2 == 0) {
                output.push_back(num);
            }
        }
        for (int num : nums) {
            if (num % 2 == 1) {
                output.push_back(num);
            }
        }
        return output;
    }
};