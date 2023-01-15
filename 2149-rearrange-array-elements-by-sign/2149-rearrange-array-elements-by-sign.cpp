class Solution {
public:
    //Brute-Force
    //TC:O(N) SC:O(N)
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>p,n;
        for(int i=0;i<size(nums);i++){
            if(nums[i] > 0) p.push_back(nums[i]);
            else if(nums[i] < 0) n.push_back(nums[i]);
        }
        for(int i=0;i<size(p);i++){
            nums[2*i] = p[i];
            nums[2*i+1] = n[i];
        }
        return nums;
    }
};