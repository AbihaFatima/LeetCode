class Solution {
public:
    bool checkValidString(string s) {
        stack<int>left,star;
        //Storing the indices of left parenthesis and star in stacks
        for(int i=0;i<size(s);i++){
            if(s[i] == '(') left.push(i);
            else if(s[i] == '*') star.push(i);
            else{   //for right parenthesis
                if(!left.empty()) left.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        //Case if left stack is not empty
        while(!left.empty()){
            if(!star.empty() && star.top()>left.top()){ //to balance "(" we need "*" to the right side of "("
                left.pop();
                star.pop();
            }
            else return false; //if star stack is empty
        }
        return left.empty(); //eg. "***(()"
    }
};