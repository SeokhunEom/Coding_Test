class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int output = 0;
        int temp = 0;
        for(int num: nums) {
            temp = num == 0 ? 0 : temp + 1;
            output = output > temp ? output : temp;            
        }
        return output;
    }
};