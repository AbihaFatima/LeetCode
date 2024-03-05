class Solution {
public:
    //Kadanes Algo tc: O(N)
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int product=1, n=nums.size();
        for(int i=0;i<n;i++){
            product *= nums[i];
            ans = max(ans, product);
            if(product == 0) product=1;
        }
        product=1;
        for(int i=n-1;i>=0;i--){
            product *= nums[i];
            ans = max(ans, product);
            if(product == 0) product=1;
        }
        return ans;
    }
};