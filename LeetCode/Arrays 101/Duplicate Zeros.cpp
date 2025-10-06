class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        vector<int> output;
        for (int n: arr) {
            output.push_back(n);
            if (n == 0) {
                output.push_back(0);
            }
        }
        for (int i = 0; i < len; i++) {
            arr[i] = output[i];
        }
    }
};