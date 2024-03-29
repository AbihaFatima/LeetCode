class SnapshotArray {
public:
    vector<map<int,int>> arr;
    int snap_id=0;
    SnapshotArray(int length) {
        arr.resize(length);
        for(int i=0;i<length;i++){
            arr[i][0]=0;
        }
    }
    
    void set(int index, int val) {
        arr[index][snap_id]=val;
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        //if snap_id is not present, it returns the closest value less than snap_id from prev. snapshots
        if(arr[index].find(snap_id)==arr[index].end()){
            auto it = --arr[index].lower_bound(snap_id);
            return it->second;
        }
        return arr[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */