class Solution {
public:
    //Time Complexity : O(N)
    //Space Complpexity : O(N) for stack
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        
        for(int i=0;i<n;i++){
            
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {
                
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                
                if (tokens[i] == "+")
                    s.push(a+b);
                else if (tokens[i] == "-")
                    s.push(a-b);
                else if (tokens[i] == "*")
                    s.push(a*b);
                else if (tokens[i] == "/")
                    s.push(a/b);
            } 
            else {
                int val = stoi(tokens[i]);
                s.push(val);
            }
        }
        return s.top();
    }
};