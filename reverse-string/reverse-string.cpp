class Solution {
    //Recursive Approach
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;
        reverseRecursive(s, start, end);
    }
    
    void reverseRecursive(vector<char>&s, int start, int end){
        int temp = s[start];
        if(start>=end){
            return;
        }
        else
        {
            temp = s[start];
            s[start]=s[end];
            s[end] = temp;
            
            reverseRecursive(s, start+1, end-1);
        }
    }
};