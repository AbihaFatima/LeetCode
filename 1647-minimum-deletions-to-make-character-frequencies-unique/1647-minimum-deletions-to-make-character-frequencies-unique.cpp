class Solution {
public:
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(auto f : s){
            freq[f-'a']++;
        }
        
        sort(freq.begin(), freq.end());
        
        int prev=0,del=0;
        
        for(int i=24;i>=0;i--){
            if(freq[i]==0) break;
            if(freq[i]>=freq[i+1]){
                prev = freq[i];
                freq[i] = max(0, freq[i+1]-1);
                del += prev-freq[i];
            }
        }
        return del;
    }
};