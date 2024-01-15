class Solution {
public:
    int calculateTime(string key, string w) {
        unordered_map<char,int>hash;
        for(int i=0;i<key.size();i++) hash[key[i]]=i;
        int pos=0,res=0;
        for(int i=0;i<w.size();i++){
            res+=abs(hash[w[i]]-pos);
            pos=hash[w[i]];
        }
        return res;
    }
};