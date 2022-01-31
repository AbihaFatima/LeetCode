class Solution {
public:
    //Approach:
    //while iterating mark the position of each character
    //At ith character, check the previous occurance and decide the start of the substring accordingly
    //Self explanatory code
    int lengthOfLongestSubstring(string s) {
        
        int max_len=0,start=-1;
        vector<int>v(256,-1);
        
        for(int i=0;i<s.size();i++)
        {
            if(v[s[i]]>start){
                start = v[s[i]];
            }
            v[s[i]] = i;
            max_len = max(max_len,i-start);
        }
        return max_len;
    }
};