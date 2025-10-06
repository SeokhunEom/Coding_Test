class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int prev;
        bool flag;

        if (arr.size() < 3) {
            return false;
        }

        for (int i = 1; i < arr.size() - 1; i++) {
            prev = arr[0];
            flag = true;
            for (int j = 1; j <= i; j++) {
                if (arr[j] <= prev) {
                    flag = false;
                    break;
                }
                prev = arr[j];
            }
            if (flag == false) {
                continue;
            }

            prev = arr[i];
            flag = true;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] >= prev) {
                    flag = false;
                    break;
                }
                prev = arr[j];
            }
            if (flag == true) {
                return true;
            }
        }
        return false;
    }
};