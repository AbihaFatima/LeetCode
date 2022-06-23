class Solution {
public:
    //Comparator function to sort the lastDay in increasing order
    static bool cmp(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),cmp);
        
        //Max-Heap to store the duration of the course
        priority_queue<int> q;
        int time=0,i=0;
        
        for(int i=0;i<courses.size();i++){
            if(time+courses[i][0] <= courses[i][1]){
                time += courses[i][0];
                q.push(courses[i][0]);
            }
            else if(q.size()!=0 && q.top()>courses[i][0]){
                int x = q.top();
                time -= x;
                q.pop();
                time += courses[i][0];
                q.push(courses[i][0]);
            }
        }
        return q.size();
    }
};