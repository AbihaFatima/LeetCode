class Solution {
public:
    //Time Complexity O(N)
    //Space Complexity O(N)
    bool backspaceCompare(string s, string t) {
        stack<int> stackS;
        stack<int> stackT;
        
        int i=0;
        while(s[i]!='\0'){
            if(s[i]=='#'){
                if(!stackS.empty()){
                    stackS.pop();
                }
            }
            else{
                    stackS.push(s[i]);
                }
            i++;
        }
        
        i=0;
            
        while(t[i]!='\0'){
            if(t[i]=='#'){
                if(!stackT.empty()){
                    stackT.pop();
                }
            }
             else{
                    stackT.push(t[i]);
                }
                i++;
        }
        
        bool flag = true;
        while(!stackS.empty() && !stackT.empty()){
            if(stackS.top() != stackT.top()){
                flag = false;
                break;
            }
            stackS.pop();
            stackT.pop();
        }
            return flag && (stackS.empty() && stackT.empty());
            
        }
};