#define ll long long
class Solution {
public:
    //Binary Search starting from min and max values of nums to find an optimal target number
    //TC: O(Nlog(maxVal - minVal))
    //SC:O(1)
    
    ll minCostTarget(vector<int>& nums, vector<int>& cost, ll target){
        ll ans=0;
        //calc min cost
        for(int i=0;i<size(nums);i++){
            ans += abs(nums[i]-target)*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll start= *min_element(nums.begin(),nums.end());
        ll end = *max_element(nums.begin(),nums.end());
        while(start<end){
            ll mid = start + (end-start)/2;
            ll minPrefix = minCostTarget(nums,cost,mid);
            ll minSuffix = minCostTarget(nums,cost,mid+1);
            if(minPrefix < minSuffix) end = mid;
            else start=mid+1;
        }
        return minCostTarget(nums,cost,start);
    }
};