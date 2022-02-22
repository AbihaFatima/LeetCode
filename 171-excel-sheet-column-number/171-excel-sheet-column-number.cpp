class Solution {
public:
    //Time Complexity : O(n)
    //Space Complexity : O(1)
    int titleToNumber(string str) {
        int n = str.length();
        int result = 0;
        for(int i=0;i<n;i++){
            int c = (char)str[i] - 'A' + 1;
            result = (26*result) + c;
        }
        return result;
    }
};