class Solution {
public:
    vector<string>res;
    string s;
    vector<string> restoreIpAddresses(string _s) {
        s=_s;
        dfs(0,0,"");
        return res;
    }
    void dfs(int u,int k,string path){
        if(u==s.size()&&k==4) {
            path.pop_back();
            res.push_back(path);
            return;
        }
        if(k==4) return;
        for(int i=u,t=0;i<s.size();i++){
            if(i>u && s[u]=='0') break;
            t=t*10+s[i]-'0';
            if(t<=255) dfs(i+1,k+1,path+to_string(t)+'.');
            else break;
        }
    }
};