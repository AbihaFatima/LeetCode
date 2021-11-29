//Brute-force approach [Time : O(n^2)]
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& input) {
//         int n = input.size();
// 	       vector<int> output(n);
	    
//         for(int i = 0; i<n; i++) {
//             int j = (i+1)%n;
//             while(j != i) {
//                 if(input[j] > input[i]) {
//                     output[i] = input[j];
//                     break;
//                 }
//                 j = (j+1)%n;
//             }
//             if(j == i)
//                 output[i] = -1;
//     	}
//         return output;
//     }
// };


//Optimised (Using stack : Single looking traversal) [Time : O(n)] [space : O(n)]
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);//Usually we don't consider the space complexity for storing ans or results
        stack<int> st;

        for(int i = 2*n-1; i>=0; i--) {
            int idx = i%n;

            if(st.empty()) {
                result[idx] = -1;
            } else {
                while(!st.empty() && st.top() <= nums[idx]) {
                    st.pop();
                }
                result[idx] = st.empty() ? -1 : st.top();
            }
            st.push(nums[idx]);
        }

        return result;
    }
};