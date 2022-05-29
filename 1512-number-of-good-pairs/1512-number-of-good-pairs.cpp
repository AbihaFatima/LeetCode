class Solution {
public:
    //Brute-force solution
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0,j;
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j] && i<j) ans++;
            }
        }
        return ans;
    }
};