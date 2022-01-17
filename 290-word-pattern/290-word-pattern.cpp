class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
        stringstream ss(s);
        string cur;
        vector<string>sList;
        while(!ss.eof()) {
            ss>>cur;
            sList.push_back(cur);
        }

        if(sList.size()!=pattern.size()) return false;
        int n=pattern.size();
        unordered_set<string>st;
        
        for(int i=0;i<n;i++){
            cur=sList[i];
            if(mp.find(pattern[i])!=mp.end()) {
                if(mp[pattern[i]]!=cur) return false;
            }else {
                if(st.find(cur)!=st.end()) return false;
                mp[pattern[i]]=cur;
                st.insert(cur);
            }
        }
        return true;
    }
};