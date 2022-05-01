class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return extract(s)==extract(t);
    }
    string extract(string& s){
        string res;
        for(auto c:s){
            if(c=='#') {
                if(res.size()) res.pop_back();
            }else res.push_back(c);
        }
        return res;
    }
};