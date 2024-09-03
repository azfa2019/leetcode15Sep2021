class Solution {
public:
    int getLucky(string s, int k) {
        string s1="";
        for(auto&c:s) s1=s1+to_string(c-'a'+1);
        string cur;
        while(k--){
            int tmp=0;
            for(auto&c:s1) tmp+=c-'0';
            s1=to_string(tmp);
            // cout<<cur<<endl;
        }
        return stoi(s1);
    }
};