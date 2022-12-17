class Solution {
public:
    //Time Complexity : O(N)
    //Space Complpexity : O(N) for stack
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        int n = tokens.size();
        
        for(int i=0;i<n;i++){
            
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {
                
                long long b = s.top();
                s.pop();
                long long a = s.top();
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
                long long val = stoll(tokens[i]);
                s.push(val);
            }
        }
        return s.top();
    }
};