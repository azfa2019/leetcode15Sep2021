class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>cur;
        dfs(s,ans,cur);
        return ans;
    }
    void dfs(string& s,vector<vector<string>>&ans, vector<string>& cur){
        if(s.size()==0) {
            ans.push_back(cur);
            return;
        }
        for(int i=1;i<=s.size();i++){
            string pre=s.substr(0,i);
            if(palin(pre)){
                cur.push_back(pre);
                string rest=s.substr(i);
                dfs(rest,ans,cur);
                cur.pop_back();
            }
        }
    }
    bool palin(string& s){
        if(s.size()==0) return true;
        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++,r--;
        }
        return true;
    }
};