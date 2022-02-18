class Solution {
    int n;
    vector<string>pool;
    public:
    string removeKdigits(string num, int k) {
        string res;
        for(char c:num){
            while(k && res.size() && res.back()>c){
                k--;
                res.pop_back();
            }
            res.push_back(c);
        }
        while(k) res.pop_back(),k--;
        int i=0;
        while(res[i]=='0') i++;
        return res.size()==i?"0":res.substr(i);
    }
};
//214247
//212