class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        while((i>=0) || (j>=0) || (carry!=0)){
            int ival = i>=0 ? num1[i]-'0' : 0;
            int jval = j>=0 ? num2[j]-'0' : 0;
            i--;
            j--;
            int sum = ival + jval + carry;
            carry = sum/10;
            res += '0' + (sum % 10);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};