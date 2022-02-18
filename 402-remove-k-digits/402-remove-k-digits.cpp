class Solution {
    int n;
    vector<string>pool;
    public:
    string removeKdigits(string num, int k) {
        string res;
        for(auto x:num){
            while(res.size() && x<res.back() && k){
                res.pop_back();
                k--;
            }
            res.push_back(x);
        }
        while(k) res.pop_back(),k--;
        int i=0;
        while(res[i]=='0') i++;
        return i==res.size()?"0":res.substr(i);
    }
};
//214247
//212