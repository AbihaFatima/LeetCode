class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> indices;
        for(int i = 0; i < nums2.size(); i++)
            indices[nums2.at(i)] = i;
        vector<int> greaterElements;
        for(int i = 0; i < nums1.size(); i++){
            int index = indices[nums1.at(i)];
            bool foundGreaterElement = false;
            for(int right = index + 1; right < nums2.size(); right++){
                if(nums2.at(right) > nums1.at(i)){
                    greaterElements.push_back(nums2.at(right));
                    foundGreaterElement = true;
                    break;
                }
            }
            if(!foundGreaterElement)
                greaterElements.push_back(-1);
        }
        return greaterElements;
    }
};