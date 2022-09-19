//TC: O(N)
//SC: O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int ans=0,currCount=1,prevCount=0;
        
        for(int i=1;i<n;i++){
            if(s[i-1] == s[i]) currCount++;
            else{
                ans += min(currCount,prevCount);
                prevCount = currCount;
                currCount = 1; //Reset curr back to 1 for next window
            }
        }
        
        return ans + min(currCount,prevCount);
    }
};