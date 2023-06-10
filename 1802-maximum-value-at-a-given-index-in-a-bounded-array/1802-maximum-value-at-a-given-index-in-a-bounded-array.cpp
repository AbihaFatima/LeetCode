class Solution {
public:
    long sum(long n){
        return (n*(n+1))/2;
    }
    
    int maxValue(int n, int idx, int maxSum) {
        long l = 1, r=maxSum, ans=0, i=idx, j=n-idx-1;
        
        while(l<=r){
            long mid = l+(r-l)/2, m=mid-1; 
            long leftSum = i>=m?(sum(m) + i-m):(sum(m) - sum(m-i));
            long rightSum = j>=m?(sum(m) + j-m):(sum(m) - sum(m-j));
            
            //checking for validity
            if(leftSum+rightSum+mid<=maxSum){ 
                ans = mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};