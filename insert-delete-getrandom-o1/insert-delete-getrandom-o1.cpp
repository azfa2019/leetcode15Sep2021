class RandomizedSet {
  vector<int>v;
  unordered_map<int,int>hash;
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
      int valPos=hash[val];
      int lastPos=v.size()-1;
      v[valPos]=v[lastPos];
      hash[v[valPos]]=valPos;
      v.pop_back();
      hash.erase(val);
      return true;
    }
    
    int getRandom() {
      int size=v.size();
      int tmp=rand()%size;
      return v[tmp];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */