class Solution {
public:
    // //TC:O(N) SC:O(N)
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     vector<int>p,n;
    //     for(int i=0;i<size(nums);i++){
    //         if(nums[i] > 0) p.push_back(nums[i]);
    //         else if(nums[i] < 0) n.push_back(nums[i]);
    //     }
    //     for(int i=0;i<size(p);i++){
    //         nums[2*i] = p[i];
    //         nums[2*i+1] = n[i];
    //     }
    //     return nums;
    // }
    
    //Using one vector
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>res(size(nums));
        int pos=0,neg=1;
        for(int i=0;i<size(nums);i++){
            if(nums[i]>0){
                res[pos] = nums[i];
                pos+=2;
            }
            else{
                res[neg] = nums[i];
                neg+=2;
            }
        }
        return res;
    }
    
};