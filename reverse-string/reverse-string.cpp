class Solution {

public:
    //Iterative Solution:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;
        while(start<end){
            swap(s[start++],s[end--]);
        }

    }
    
    
    
    
    
        //Recursive Approach
    //     void reverseString(vector<char>& s) {
    //     int start = 0;
    //     int end = s.size()-1;
    //     reverseRecursive(s, start, end);
    // }
    
//     void reverseRecursive(vector<char>&s, int start, int end){
//         int temp = s[start];
//         if(start>=end){
//             return;
//         }
//         else
//         {
//             temp = s[start];
//             s[start]=s[end];
//             s[end] = temp;
            
//             reverseRecursive(s, start+1, end-1);
//         }
//     }
};