class Solution {
public:
    //Time Complexity : O(N) for iterating throughout once
    //Space Complexity : O(N) for using extra space stack
    
    bool isValid(string s) {
        stack<int> Stack;
        int n = s.length();
        
        for(int i=0;i<n;i++){
            
            //If opening bracket push to stack
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                Stack.push(s[i]);
            }
            
            else{
                //if stack is empty eg test case: s="]()" return false
                if(Stack.empty())
                    return false;
                
                char c= Stack.top();
                Stack.pop();
                //Check for top poped element has a corresponding closing bracket if yes then continue; else return false
                if((c=='{' && s[i]=='}') || (c=='(' && s[i]==')') || (c=='[' && s[i]==']') )
                    continue;
                else
                    return false;
            }
        }
        //At the end if string has balanced parenthesis then stack would be empty i.e return true; else return false;
        return Stack.empty();
    }
};