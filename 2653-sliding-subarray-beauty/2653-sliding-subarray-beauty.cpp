class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        vector<int>freq(51,0); //freq array of neg. numbers ranging from 1-50
        for(int i=0,j=0 ;i<size(nums); i++){
            if(nums[i]<0) freq[abs(nums[i])]++;
            if(i-j+1>=k){
                int count=0;
                //Finding xth smallest number in the curr window
                for(int l=50;l>=1;l--){
                    count+=freq[l];
                    if(count>=x){
                        ans.push_back(-l);
                        break;
                    }
                }
                //if xth smallest number doesn't exist
                if(count<x) ans.push_back(0);
                if(nums[j]<0) freq[abs(nums[j])]--;
                j++;
            }
        }
        return ans;
    }
};