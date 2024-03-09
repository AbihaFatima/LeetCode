class Solution {
public:
    int rev(int n){
        int reverse=0;
        while(n!=0){
            int digit=n%10;
            reverse = reverse*10 + digit;
            n/=10;
        }
        return reverse;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>pairs={};
        int count=0;
        int mod = 1e9+7;
        for(auto n: nums){
            int nicePair = n - rev(n);
            count = (count + pairs[nicePair])%mod;
            pairs[nicePair]++;
        }
        return count%mod;
    }
};