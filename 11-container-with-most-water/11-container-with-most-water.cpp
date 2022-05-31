class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=0;
        int n = height.size();
        int i=0, j=n-1;
        while(i<=j){
            int tempArea = (j-i) * min(height[i],height[j]);
            if(tempArea>maxA){
                maxA=tempArea;
            }
            if(height[i]>height[j]) j--; //we are moving the pointer which has smaller height
            else i++;
        }
        return maxA;
    }
};