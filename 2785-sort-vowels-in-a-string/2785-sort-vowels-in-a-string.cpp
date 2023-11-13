class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char>v{'A','E','I','O','U','a','e','i','o','u'};
        string tmp;
        for(int i=0;i<s.size();i++) if(v.count(s[i])) tmp+=s[i];
        sort(tmp.begin(),tmp.end());
        cout<<tmp<<endl;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(v.count(s[i])) s[i]=tmp[j++];
        }
        return s;
    }
};