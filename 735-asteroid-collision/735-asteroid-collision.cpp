class Solution {
public:
    //TC: O(N)
    //SC: O(N)
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        
        for(int i=0; i<ast.size();i++){
            //if element is positive push it into stack
            if(ast[i] > 0)
                st.push(ast[i]);
            
            //for negative elements
            else{
                //Case 1: if top element is less than ast[i]
                while(!st.empty() && st.top()>0 && st.top() < -ast[i]){
                    st.pop();
                }
                
                //Case 2: if top element is equal to ast[i]
                if(!st.empty() && st.top() == -ast[i]){
                    st.pop();
                }
                //Case 3: when top element is greater than ast[i] then do nothing
                else if(!st.empty() && st.top() > -ast[i]){
                    continue;
                }
                //Case 4: when moving in same direction
                else{
                    st.push(ast[i]);
                }
                
            }
        }
        
        vector<int>ans(st.size());
        int i = st.size()-1;
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        
        return ans;
    }
};