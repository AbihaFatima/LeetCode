class Solution {
public:
    string largestOddNumber(string num) {
        int len = num.size();
        string res = "";
        for (int i = len - 1; i >= 0; i--) {
            int isOdd = num[i] - '0';
            if (isOdd % 2 == 1) {
                res = num.substr(0, i + 1);
                break;
            }
        }
        return res;
    }
};