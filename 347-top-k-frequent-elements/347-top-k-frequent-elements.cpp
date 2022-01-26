class Solution {
public:
    // Time Complexity: O(N.logK)
    // Space Complexity: O(N)
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int>map;
        int n= arr.size();
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;//Creating min heap
        for(auto i=map.begin();i!=map.end();i++){
            minh.push({i->second,i->first});//Storing the (freqOfArr[i],Arr[i]) in the heap
            if(minh.size()>k){
                minh.pop();
            }
        }
        vector<int>ans;
        while(minh.size()!=0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};