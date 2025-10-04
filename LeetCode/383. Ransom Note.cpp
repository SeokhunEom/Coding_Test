class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alphabetCnt[26] = {0, };

        for (char c: magazine) {
            alphabetCnt[c - 'a']++;
        }

        for (char c: ransomNote) {
            alphabetCnt[c - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (alphabetCnt[i] < 0) {
                return false;
            }
        }
        return true;
    }
};