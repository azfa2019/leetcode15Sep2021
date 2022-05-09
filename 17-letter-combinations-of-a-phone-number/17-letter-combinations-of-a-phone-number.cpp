class Solution {
    int n;
    vector<string>res;
    string hash[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        n=digits.size();
        dfs(0,digits,"");
        return res;
    }
    void dfs(int idx,string& digits,string s){
        if(idx==n) res.push_back(s);
        else {
            for(auto c:hash[digits[idx]-'0']) dfs(idx+1,digits,s+c);
        }
    }
};