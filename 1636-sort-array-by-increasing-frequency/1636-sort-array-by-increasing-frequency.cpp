class Solution {
public:
    //Time Complexity : O(NlogN) using max heap 
    //Space Complexity : O(1) if not considering result vector else O(N)
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        //Making max heap and storing freq,element in heap;
        priority_queue<pair<int,int>> maxh;
        for(auto i=map.begin();i!=map.end();i++){
            maxh.push({-i->second,i->first});
        }
        vector<int>ans;
        while(maxh.size()!=0){
            int freq = maxh.top().first;
            int element = maxh.top().second;
            for(int i=0;i<abs(freq);i++){
                ans.push_back(element);
            }
            maxh.pop();
        }
        return ans;
    }
};