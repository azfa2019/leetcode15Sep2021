class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>tmp;
        string str;
        stringstream ss(sentence);
        while(ss>>str) tmp.push_back(str);
        for(auto&s:tmp) cout<<s<<endl;
        for(int i=0;i<tmp.size();i++)
            if(check(tmp[i],searchWord)) return i+1;
        return -1;
    }
    bool check(string s,string pre){
        bool flag=true;
        for(int i=0;i<pre.size();i++){
            if(i==s.size()) {
                flag=false;
                break;
            }
            if(s[i]!=pre[i]) return false;
        }
        return flag;
    }
};