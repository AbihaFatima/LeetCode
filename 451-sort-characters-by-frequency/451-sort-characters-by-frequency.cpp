//TC: O(NlogN)
//SC: O(N)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>,vector<pair<int,char>>> maxH;// freq , character
        for(char it: s){
            mp[it]++;
        }
        for(auto it : mp){
            maxH.push({it.second, it.first});
        }
        string ans="";
        
        while(maxH.size()>0){
            int freq = maxH.top().first;
            char ch = maxH.top().second;
            for(int j=0; j<freq; j++){
              ans+=ch; // append as many times of freq
            }
            maxH.pop(); //Heapify happens 
        }
        return ans;
    }
};