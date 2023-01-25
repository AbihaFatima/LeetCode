class Solution {
public:
    int minimumCardPickup(vector<int>& card) {
        unordered_map<int,int>mp;
        int minCount=INT_MAX;
        for(int i=0;i<card.size();i++){
            //If card is already present in the map
            if(mp.count(card[i])){
                int count = i-mp[card[i]]+1;
                minCount = min(minCount, count);
            }
            //Else insert the index of the card
            mp[card[i]]=i;
        }
        return (minCount==INT_MAX) ? -1 : minCount;
    }
};