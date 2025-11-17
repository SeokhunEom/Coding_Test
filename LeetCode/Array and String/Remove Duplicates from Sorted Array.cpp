class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        bool flag[201] = {false};
        for (int i = 0; i < nums.size(); i++) {
            if (flag[nums[i] + 100] == false) {
                nums[k++] = nums[i];
                flag[nums[i] + 100] = true;
            }
        }
        return k;
    }
};