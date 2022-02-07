class Solution {
public:
    //Brute-force Approach
    //Time Complexity: O(NlogN)
    //Space Complexity : O(1)
    // char findTheDifference(string s, string t) {
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     char ch;
    //     for(int i=0;i<t.size();i++){
    //         if(s[i]!=t[i]){
    //             ch = t[i];
    //             break;
    //         }
    //     }
    //     return ch;
    // }
    
    
    //Optimised Approach - using difference in ASCII values of char
    //Time Complexity : O(N)
    //Space Complexity : O(1)
    char findTheDifference(string s, string t) {
        int sum1 = 0;
        int sum2 = t[s.size()];
        for(int i=0;i<s.size();i++){
            sum1 += s[i];
            sum2 += t[i];
        }
        return char(abs(sum2-sum1));
    }
    
};