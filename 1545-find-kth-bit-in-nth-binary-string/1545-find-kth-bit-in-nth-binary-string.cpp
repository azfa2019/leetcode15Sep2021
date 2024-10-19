class Solution {
public:
    char findKthBit(int n, int k) {
        string res="0";
        n--;
        // string tmp="1101";
        // cout<<reverse(tmp)<<endl;
        while(n--){
            string tmp=res;
            res=res+'1';
            res=res+reverse(invert(tmp));
        }
        return res[k-1];
    }
    string invert(string s){
        string res="";
        for(auto& c:s)
            res+='1'-c+'0';
        return res;
    }
    string reverse(string s){
        string res="";
        for(int i=s.size()-1;i>=0;i--)
            res.push_back(s[i]);
        return res;
    }
};