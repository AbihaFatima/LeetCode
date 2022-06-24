class Solution {
public:
    /*
    TC: O(N + logK*logN)
    SC: O(N)
    */
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) 
            return target[0] == 1;
        
        priority_queue<int> pq;
        long sum=0;
        for(int i=0;i<target.size();i++){
            sum += target[i];
            pq.push(target[i]);
        }
        
        while(pq.top() != 1) {// repeat till all elements haven't been made equal to 1
            long largest = pq.top(); 
            pq.pop();
            long largest_2 = pq.top(), 
            restArrSum = sum - largest;
            // n = number of subtraction to get largest below 2nd largest element. max(1, ..) denotes teh case where largest and largest_2 are equal
            int n = max(1l, (largest - largest_2) / restArrSum);
            largest -= (restArrSum * n); // subtracting from largest n times till it gets lower than 2nd largest
            
            pq.push(largest);            // push the modifed element back in
            sum = restArrSum + largest;  // update the sum of array
            if(largest < 1) return false;// if an element gets below 1, we cant achieve original array
        }
        return true;
    }
};