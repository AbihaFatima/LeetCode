class Solution {
public:
    /*
    1. intution is to traverse the nested loop i(0--n) & j(i+1--n). While in second loop we iterate for other 2 more numbers, becasue we need 4 numbers whose sum is equal to the target.
    2. So we check for the number using the front and back method (two pointer).
    3. While traversing we check for the repetition if we find the repetition we make the jump.
    4. When we find the numbers whose sum is equal to our given target, then we make the vector to store the 4 numbers, then we push that vector in our main vector of vector.
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    vector<vector<int>>ans;
    if(nums.empty()){
        return ans;
    }
    int n=nums.size();
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){
            
            int target_2=target-nums[j]-nums[i];
            int front=j+1;
            int back=n-1;
            while(front<back){
                int twoSum=nums[front]+nums[back];
                if(twoSum<target_2){
                    front++;
                }
                else if(twoSum>target_2){
                    back--;
                }
                else{
                    vector<int>quadruplet(4,0);
                    quadruplet[0]=nums[i];
                    quadruplet[1]=nums[j];
                    quadruplet[2]=nums[front];
                    quadruplet[3]=nums[back];
                    ans.push_back(quadruplet);
                    
                    while(front<back && nums[front]==quadruplet[2]){
                        front++;
                    }
                    while(front<back && nums[back]==quadruplet[3]){
                        back--;
                    }
                }
            }
            while(j+1<n && nums[j+1]==nums[j]){
                j++;
            }                
        }
        while(i+1<n && nums[i+1]==nums[i]){
            i++;
        }
    }
    return ans;
    }
};