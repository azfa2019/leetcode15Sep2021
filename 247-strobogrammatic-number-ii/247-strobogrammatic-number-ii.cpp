class Solution {
    vector<string>res;
    unordered_map<string,string>hash{{"0","0"},{"1","1"},{"8","8"},{"6","9"},{"9","6"}};
    public:
    vector<string> findStrobogrammatic(int n) {
        string cur;
        if(n%2) {
            cur="0";
            dfs(cur,n-1);
            cur="1";
            dfs(cur,n-1);
            cur="8";
            dfs(cur,n-1);
        }else{
            cur="";
            dfs(cur,n);
        }
        return res;
    }
    void dfs(string& cur,int n){
        if(n==0) {
            res.push_back(cur);
            return;
        }
        for(auto item:hash){
            if(item.first=="0" && n==2) continue;
            string tmp=item.first+cur+item.second;
            dfs(tmp,n-2);
        }
    }
};