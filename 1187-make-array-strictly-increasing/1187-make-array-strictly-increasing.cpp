class Solution {
public:
int dp[2001][2001],n=2000,ans=2001;
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort(arr2.begin(),arr2.end());
        
        //removes consecutive duplicate elements from the sorted range 
        auto result = unique(arr2.begin(), arr2.end());
        //resizes arr2 to the size specified by the distance between arr2.begin() and the result iterator.
        //so arr2 will now contain only the unique elements in the original sorted order
        arr2.resize(distance(arr2.begin(), result));
        
        // Initialize dp array with a large value
        memset(dp,0x3f,sizeof(dp));
        
        // Initialize the first row of dp array
        for(int i = 0; i < arr2.size(); ++i) dp[0][i] = 1;
        dp[0][n] = 0;
        
        for(int i=1;i<arr1.size();++i){
            for(int j=0;j<arr2.size();++j){
                //minimum number of operations if we include arr2[j]
                if(j)
                    dp[i][j]=min(dp[i-1][j-1]+1,dp[i][j-1]);
                //minimum number of operations if we exclude arr2[j]
                if(arr2[j]>arr1[i-1])
                    dp[i][j]=min(dp[i][j],dp[i-1][n]+1);
                //minimum number of operations if we replace arr1[i] with arr2[j]
                if(arr1[i]>arr2[j])
                    dp[i][n]=min(dp[i-1][j],dp[i][n]);
                
                // Update the minimum number of operations for the last row
                if(i==arr1.size()-1)
                    ans=min(ans,dp[i][j]);
            }
            //Update the minimum number of operations for the last row (excluding arr2)
            if(arr1[i]>arr1[i-1])
                dp[i][n]=min(dp[i][n],dp[i-1][n]);
            //Update the minimum number of operations for the last row (including arr2)
            if(i==arr1.size()-1)
                ans=min(ans,dp[i][n]);
        }
        //If ans is greater than arr1 size, not possible to make the array strictly increasing
        if(ans>arr1.size())return -1;
        return ans;
    }
};