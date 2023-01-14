class Solution {
public:
    // //using vector of pairs
    // vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    //     vector<pair<int,string>>v;
    //     for(int i=0;i<names.size();i++){
    //         v.push_back({heights[i],names[i]});
    //     }
    //     sort(v.rbegin(),v.rend());
    //     for(int i=0;i<names.size();i++){
    //         names[i] = v[i].second;
    //     }
    //     return names;
    // }
    
    
    //Using Max-Heap
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int,string>>pq;
        for(int i=0;i<names.size();i++){
            pq.push({heights[i],names[i]});
        }
        int i=0;
        while(i <= names.size() && !pq.empty()){
            names[i] = pq.top().second;
            pq.pop();
            i++;
        }
        return names;
    }
};