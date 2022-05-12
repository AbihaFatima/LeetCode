class Solution {
public:
    //Time Complexity: O(Sigma(P(N,K)), where P is the k permutation of n or partial permutation. More formally, P(N, k) = (N!)/((N-k)!).
    
    //Space Complexity: O(N!), since we have to store all the possible solutions which are N! in size where N is the size of the array.
    
    void permutation(vector<int>& nums, int i,vector<vector<int>>&ans){
        int n= nums.size();
        if(i==n){
            ans.push_back(nums);
        }
        
        else{
        for(int j=i; j<n;j++){
            swap(nums[i],nums[j]);
            permutation(nums,i+1,ans); //i is increased by one so that swapping is done with next index element in further calls
            swap(nums[i],nums[j]); //Backtracking - swapping it back to original order after recursion call is over
        }
    }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(nums, 0, ans);
        return ans;
    }
};