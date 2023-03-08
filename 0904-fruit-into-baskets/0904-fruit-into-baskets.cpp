class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // here key is the type of the fruit 
        // and value is the number of fruits of 'key' type in the current window
        unordered_map<int,int>mp;
        int left=0,right=0;
        int res=0;
        for(right=0;right<fruits.size();right++){
            mp[fruits[right]]++;
            // as long as there are more than 2 types of fruit, shrink the window
            while(mp.size()>2){
                if(mp[fruits[left]]==1) mp.erase(fruits[left]);
                else mp[fruits[left]]--;
                left++;
            } 
            res=max(res, right-left+1);
        }
        return res;
    }
};