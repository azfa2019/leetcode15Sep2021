class Solution {
public:
    unordered_set<string>hash;
    int res=0;
    int maxUniqueSplit(string s) {
        dfs(s,0);
        return res;
    }
    void dfs(string s, int pos){
        if(s.size()-pos+hash.size()<=res) return;
        if(pos==s.size()){
            res=max(res,(int)hash.size());
            return;
        }
        string temp;
        for(int i=pos;i<s.size();i++){
            temp+=s[i];
            if(hash.find(temp)==hash.end()){
                hash.insert(temp);
                dfs(s,i+1);
                hash.erase(temp);
            }
        }
    }
};