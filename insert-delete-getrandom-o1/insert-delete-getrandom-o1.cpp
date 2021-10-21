class RandomizedSet {
  unordered_map<int,int>hash;
  vector<int>v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
      if(hash.find(val)!=hash.end()) return false;
      v.push_back(val);
      hash[val]=v.size()-1;
      return true;
    }
    
    bool remove(int val) {
      if(hash.find(val)==hash.end()) return false;
      
      int lastPos=v.size()-1;
      int valPos=hash[val];
      v[valPos]=v[lastPos];
      v.pop_back();
      hash[v[valPos]]=valPos;
      hash.erase(val);
      return true;
    }
    
    int getRandom() {
      int size=v.size();
      int pos=rand()%size;
      return v[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */