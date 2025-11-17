class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int idxA = a.size() - 1;
        int idxB = b.size() - 1;
        int carry = 0;
        int sum;
        
        while(idxA >= 0 || idxB >= 0) {
            sum = carry;
            if(idxA >= 0) {
                sum += a[idxA] - '0';
                idxA--;
            }
            if(idxB >= 0) {
                sum += b[idxB] - '0';
                idxB--;
            }
            result = char((sum % 2) + '0') + result;
            carry = sum / 2;
        }
        if(carry > 0) {
            result = char(carry + '0') + result;
        }
    
        return result;
    }
};