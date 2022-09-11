class Solution {
public:
        int mostFrequentEven(vector<int>& nums) {
            map<int,int>mp;
            int ans = -1;
            for(auto it : nums){
                    mp[it]++;
            }
            int max_count = -1;
            for(auto i : mp){
                if (i.first % 2 == 0 and max_count < i.second) {
                    ans = i.first;
                    max_count = i.second;
                }
            }
            return ans;
    }
};