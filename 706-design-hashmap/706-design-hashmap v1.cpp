const int N=20003;
typedef pair<int,int> PII;
class MyHashMap {
    vector<PII>h[N];
public:
    MyHashMap() {
        
    }
    int find(vector<PII>&h,int key){
        for(int i=0;i<h.size();i++)
            if(h[i].first==key) return i;
        return -1;
    }
    void put(int key, int value) {
        int t=key%N;
        int k=find(h[t],key);
        if(k==-1) h[t].push_back({key,value});
        else h[t][k].second=value;
    }
    
    int get(int key) {
        int t=key%N;
        int k=find(h[t],key);
        if(k==-1) return -1;
        else return h[t][k].second;
    }
    
    void remove(int key) {
        int t=key%N;
        int k=find(h[t],key);
        if(k!=-1) h[t].erase(h[t].begin()+k);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
