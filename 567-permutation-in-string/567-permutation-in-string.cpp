class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1_freq(26,0);   
        vector<int> f2_freq(26,0);   
        int s1_len = s1.size();
        int s2_len = s2.size();
        
        if(s1_len > s2_len) return false;
        
        int left=0,right=0;
        // compute the frequency of each char for the first window
        while(right<s1_len){
            f1_freq[s1[right]-'a'] += 1;
            f2_freq[s2[right]-'a'] += 1;
            right++;
        }
        
        right -= 1;
        
        // search the remaining windows
        while(right < s2_len){
            if(f1_freq == f2_freq) return true;
            right += 1;
            // add the current char current window
            if(right != s2_len){
                f2_freq[s2[right]-'a'] += 1;
            }
            // remove the first char of current window 
            f2_freq[s2[left]-'a'] -= 1;
            left += 1;
        }
        return false;
    }
};