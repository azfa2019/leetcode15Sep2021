class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>pos;
        unordered_set<char>st;
        for(char c:order) st.insert(c);
        string ans;
        for(char c:order){
            for(char c2:s){
                if(c==c2) ans=ans+c;
            }
        }
        for(int i=0;i<s.size();i++) 
            if(!st.count(s[i])) {
                int m=ans.size();
                if(i<m){
                    ans=ans.substr(0,i+1)+s[i]+ans.substr(i+1);
                }else if(i==m){
                    ans=ans.substr(0,i+1)+s[i];
                }  
            }
        //cout<<ans;
        return ans;
    }
};