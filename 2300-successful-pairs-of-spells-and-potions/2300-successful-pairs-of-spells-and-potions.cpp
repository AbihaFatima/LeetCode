#define ll long long 
class Solution {
public:
    //Binary Search Solution
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        int n=potions.size();
        for(int i=0;i<spells.size();i++)
        {
            ll low=0,high=n-1,mid;
            ll index=-1;
            while(low<=high){
                mid = low + (high-low)/2;
                ll target=spells[i] *1ll * potions[mid];
                if(target >= success){
                    high=mid-1;
                    index=mid;
                }
                else
                    low=mid+1;
            }
            if(index==-1) ans.push_back(0);
            else ans.push_back(n-index);
        }
        return ans;
    }
};