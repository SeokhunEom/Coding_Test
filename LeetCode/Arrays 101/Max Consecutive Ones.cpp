class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int output = 0;
        int temp = 0;
        for(int num: nums) {
            if (num == 0) {
                temp = 0;
            } else {
                temp++;
                output = output > temp ? output : temp;
            }
            
        }
        return output;
    }
};