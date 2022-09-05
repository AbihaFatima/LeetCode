class Solution {
public:
    //Brute-force
    //TC: O(N^2)
    //SC: O(1)
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        for(int i = 0;i<n;i++){
            int minimum=nums[i];
            int maximum=nums[i];
            for(int j=i;j<n;j++){
                maximum = max(maximum,nums[j]);
                minimum = min(minimum,nums[j]);
                ans += (maximum-minimum);
            }
        }
        return ans;
    }
};