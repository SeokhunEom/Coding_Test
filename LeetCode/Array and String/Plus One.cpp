class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int sum, carry = 1;
        int digitsNum = digits.size();

        for (int i = digitsNum - 1; i >= 0; i--) {
            sum = digits[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            result.push_back(sum);
        }
        if (carry > 0) {
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};