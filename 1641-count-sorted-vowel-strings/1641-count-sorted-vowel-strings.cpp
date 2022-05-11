class Solution {
public:
    //Backtracking problem
    //Time Complexity: O(N)
    //Space Complexity: O(1)
    int countVowelStrings(int n) {
        if(n<=0) return 0; //Not required as question has contraints starting from 1, but if -ve numbers are also present it can be used accordingly
        int a=1,e=1,i=1,o=1,u=1;
        while(--n){
            o+=u;
            i+=o;
            e+=i;
            a+=e;
        }
        return a+e+i+o+u;
    }
};