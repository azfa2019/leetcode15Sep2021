class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>hash;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& q=hash[key];
        pair<int,string>p{timestamp+1,""};
        auto it=upper_bound(q.begin(),q.end(),p);
        if(it==q.begin()) return "";
        --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */