class Solution {
public:
    //Time Complexity : O(N)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n), right(n);
        stack<int> mystack;
        
        for(int i=0;i<n;++i){//fill stack
            if(mystack.empty()){
                left[i] = 0;
                mystack.push(i);
            }
            else{
                while(!mystack.empty() && heights[mystack.top()] >= heights[i])
                {
                    mystack.pop();
                }
                left[i] = mystack.empty() ? 0 : mystack.top() + 1;
                mystack.push(i);
            }
        }
        
        while(!mystack.empty()){
            mystack.pop(); //Clear stack for reuse
        }
        
        for(int i=n-1;i>=0;--i){ //For right 
            if(mystack.empty()){
                right[i] = n-1;
                mystack.push(i);
            }
            else{
                while(!mystack.empty() && heights[mystack.top()]>=heights[i]){
                    mystack.pop();
                }
                right[i] = mystack.empty() ? n-1 : mystack.top()-1;
                mystack.push(i);
            }
        } 
        
        int max_area = 0; //Stores maximum area
        for(int i=0;i<n;i++){
            max_area = max(max_area, heights[i]*(right[i]-left[i]+1));
        }
        return max_area;
        
    }
};