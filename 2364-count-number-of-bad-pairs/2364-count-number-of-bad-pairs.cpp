class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long n=nums.size();
        long total = n*(n-1)/2;
        long good=0;
        unordered_map<long,long> gPairs = {};
        for(long i=0;i<n;i++){
            good += gPairs[i-nums[i]];
            gPairs[i-nums[i]]++;
        }
        return total-good;
    }
};