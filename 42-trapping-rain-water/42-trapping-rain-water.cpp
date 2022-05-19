class Solution {
public:
    //Time Complexity : O(N)
    //We take max on left and max of right side then return minimum of right_max and left_max
    int trap(vector<int>& height) {
        
        int h=height.size();
        vector<int>left(h,0);
        vector<int>right(h,0);
        
        int curr=0;
        int res=0;
        for(int i=0; i<h;++i){
            curr=max(curr,height[i]);
            left[i]=curr;
        }
        curr=0;
        for(int j=h-1;j>=0;--j){
            curr=max(curr,height[j]);
            right[j]=curr;
        }
        
        for(int i=1; i<h-1;++i){
            int temp=min(left[i-1],right[i+1])-height[i];
            if(temp>0){
                res+=temp;
            }
        }
        return res;
    }
};