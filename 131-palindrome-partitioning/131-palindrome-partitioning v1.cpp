class Solution {
    string s;
    int n;
    vector<vector<int>>ans;
    public:
    vector<vector<string>> partition(string s) {
        this->s=s;
        this->n=s.size();
        vector<int>cur;
        dfs(0,cur);
        vector<vector<string>>res(ans.size());
        for(int j=0;j<ans.size();j++){
            auto e=ans[j];
            for(int i=0;i<e.size();i++){
                if(i==0) res[j].push_back(s.substr(0,e[i]+1));
                else res[j].push_back(s.substr(e[i-1]+1,e[i]-e[i-1]));
            }
        }
        return res;
    }
    void dfs(int idx,vector<int>&cur){
        if(idx==s.size()) {
            ans.push_back(cur);
            return;
        }
        for(int i=idx;i<n;i++){
            if(check(idx,i)) {
                cur.push_back(i);
                dfs(i+1,cur);
                cur.pop_back();
            }
        }
    }
    bool check(int i,int j){
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }

};
// dfs? 
// x x x x x x x x x x x x  
//   i     j
// 
// 
// 
