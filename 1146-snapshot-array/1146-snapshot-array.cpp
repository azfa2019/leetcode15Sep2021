class SnapshotArray {
public:
    int id=0;
    unordered_map<int,vector<pair<int,int>>>hash;
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        if(hash.count(index)&&hash[index].back().first==id){
            hash[index].back().second=val;
        }else{
            hash[index].push_back({id,val});
        }
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        if(!hash.count(index)||hash[index][0].first>snap_id){
            return 0;
        }else{
            const auto& items=hash[index];
            int l=0,r=items.size()-1;
            while(l<r){
                int mid=l+r+1>>1;
                if(items[mid].first<=snap_id) l=mid;
                else r=mid-1;
            }
            return items[l].second;
        }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */