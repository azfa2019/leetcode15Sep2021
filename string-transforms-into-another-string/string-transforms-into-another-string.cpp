class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1==str2) return true;
        int n=str1.size();
        unordered_map<char,char>mp;
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            char c1=str1[i];
            char c2=str2[i];
            st.insert(c2);
            if(mp.find(c1)==mp.end()) mp[c1]=c2;
            else {
                if(mp[c1]!=c2) return false;
            }
        }
        if(mp.size()==26 && st.size()==26) return false;
        return true;
        
    }
};