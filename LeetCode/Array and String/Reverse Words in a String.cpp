class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        string result = "";

        for (int i = 0; i < len; i++) {
            if (s[i] != ' ') {
                int j = i;
                while (j < len && s[j] != ' ') {
                    j++;
                }
                string word = s.substr(i, j - i);
                if (result.empty()) {
                    result = word;
                } else {
                    result = word + " " + result;
                }
                i = j - 1;
            }
        }
        return result;
    }
};