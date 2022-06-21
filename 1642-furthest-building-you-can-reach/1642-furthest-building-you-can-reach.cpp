class Solution {
public:
    /*
    Approach: Priority Queue
    TC: O(NlogN)
    SC: O(NlogN)
    */
    int furthestBuilding(vector<int>& height, int bricks, int ladders) {
        int i=0,diff=0; // i is used for storing the position and diff for storing difference.
        
        // Priority Queue for storing the bricks used in each step in decreasing order (Max at top)
        priority_queue<int>max_heap;
        
        // go till before the last building.
        for(i=0;i<height.size()-1;i++){
            
            //difference of the height of corresponding buildings
            diff = height[i+1] - height[i];
            
            //If next building is equal or samaller than current then go to next building.
            if(diff <= 0) continue;
            
            bricks -= diff;//taking the bricks needed for going to next building.
            max_heap.push(diff);//adding the number of bricks used in priority queue.
            
            // if bricks become negetive then there were not enough bricks. So add a ladder in place of the step where most bricks were used.
            if(bricks<0){
                bricks += max_heap.top();//taking back bricks from that step
                max_heap.pop();//As max bricks were removed so pop
                ladders--;//1 ladder used
            }
            //if ladder is negetive then the ladder was not provided to go to next building. So we can't proceed.
            if(ladders < 0) break;
        }
        
        // return the present position.
        return i;
    }
};