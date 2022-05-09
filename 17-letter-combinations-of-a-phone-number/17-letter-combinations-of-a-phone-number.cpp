class Solution {
    int n;
    vector<string>res;
    vector<vector<string>>hash{{},{},{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
public:
    vector<string> letterCombinations(string digits) {
        n=digits.size();
        if(n==0) return {};
        string s;
        dfs(0,s,digits);
        return res;
    }
    void dfs(int idx,string& s,string& digits){
        if(idx==n) {
            res.push_back(s);
            return;
        }
        for(auto c:hash[digits[idx]-'0']){
            s+=c;
            dfs(idx+1,s,digits);
            s.pop_back();
        }
    }
};