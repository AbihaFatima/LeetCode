class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string res;
        int n=path.size();
        
        for(int i=0;i<n;i++){
            if(path[i] == '/')    
                continue;
            string temp;
            // iterate till we doesn't traverse the whole string and doesn't encounter the last /
            while(i<n && path[i]!='/'){
                temp+=path[i];
                ++i;
            }
            
            if(temp==".") continue;
            
            else if(temp==".."){
                if(!st.empty()){// pop the top element from stack if exists
                    st.pop();
                }
            }
            else
                st.push(temp); // push the directory file name to stack
        }
        
        while(!st.empty()){
            res = "/"+ st.top() + res;
            st.pop();
        }
        
        if(res.size()==0) return "/";
        
        return res;
    }
};