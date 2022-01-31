class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        vector<string>ans;
        unordered_map<string,int>map1; //Making a hashmap having List1 and its index
        int minimum_sum = INT_MAX;
        
        for(int i=0;i<list1.size();i++)
        {
            map1[list1[i]]=i;
        }
        
        for(int i=0;i<list2.size();i++)
        {
            if(map1.find(list2[i]) != map1.end())//If found the element from list2 in map1
            {
                if((i+map1[list2[i]]) < minimum_sum)
                {
                    minimum_sum = i+map1[list2[i]];
                    ans.clear();
                    ans.push_back(list2[i]);
                }
                else if(map1[list2[i]]+i == minimum_sum)
                {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};