class Solution {
public:
    //Most optimised solution is using stacks
    //Time and space complexity trade off
    //Time Complexity : O(N)
    //Space Complexity : O(N)
    
    //Lets say we need three numbers such that s1<s3<s2
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        //We are making a minArr having minimum most values till left of nums[i]
        int minArr[n];
        minArr[0]=nums[0];
        
        for(int i=1 ; i<n ; i++){
            minArr[i] = min(minArr[i-1], nums[i]); //from this array we will get s1
        }
            stack<int> s;
            
            //This step is to get s2
            //We are running a loop from the end of nums that is  
            //j would be pointing to the end of nums and mini arrays
            for(int j=n-1 ; j>=0; j--){
                if(nums[j]>minArr[j]){
    
        //discarding all elements right to s2 which are smaller than s1 as we need s3>s1
                    while(!s.empty() && s.top() <= minArr[j]){  
                        s.pop();
                    }
                    
        //now st.top() is our candidate for s3 and we have ensured s1<s3<s2
                    while(!s.empty() && nums[j] > s.top()){
                        return true;
                    }
                    s.push(nums[j]);
                }
            }
        return false;
    }
};