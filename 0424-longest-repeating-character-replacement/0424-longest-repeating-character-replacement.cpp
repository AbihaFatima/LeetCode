class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,maxC=0;
        int res=-1;
        unordered_map<char,int>mp;
        int n=s.size();
        while(j<n){
            mp[s[j]]++;
            maxC=max(maxC, mp[s[j]]);
            int currLen=j-i+1;
            if(currLen-maxC > k){
                mp[s[i]]--;
                i++;
            }
            currLen=j-i+1;
            res=max(res,currLen);
            j++;
        }
        return res;
    }
};