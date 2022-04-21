const int N=100003;
class MyHashSet {
    vector<int>h[N];
public:
    MyHashSet() {
        
    }
    int find(vector<int>&h,int x){
        for(int i=0;i<h.size();i++)
            if(h[i]==x) return i;
        return -1;
    }
    void add(int key) {
        int t=key%N;
        int k=find(h[t],key);
        if(k==-1) h[t].push_back(key);
    }
    
    void remove(int key) {
        int t=key%N;
        int k=find(h[t],key);
        if(k!=-1) h[t].erase(h[t].begin()+k);
    }
    
    bool contains(int key) {
        int t=key%N;
        int k=find(h[t],key);
        return k!=-1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */