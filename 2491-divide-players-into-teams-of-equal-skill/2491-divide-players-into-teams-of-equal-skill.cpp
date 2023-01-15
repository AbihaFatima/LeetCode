class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int i=0, j=size(skill)-1;
        sort(begin(skill),end(skill));
        int sum = skill[i]+skill[j];
        long long chemistry=0;
        while(i<j){
            int tempSum = skill[i]+skill[j];
            if(sum != tempSum) return -1;
            chemistry += (skill[i]*skill[j]);
            i++;j--;
        }
        return chemistry;
    }
};