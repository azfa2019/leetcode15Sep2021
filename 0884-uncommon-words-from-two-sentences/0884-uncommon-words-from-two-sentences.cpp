class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>hash1,hash2;
        auto ss1=get(s1),ss2=get(s2);
        
        for(auto&s:ss1) hash1[s]++;
        for(auto&s:ss2) hash2[s]++;
        vector<string>ans;
        for(auto&[p,v]:hash1) {
            if(!hash2.count(p) && v==1) ans.push_back(p);
        }
        for(auto&[p,v]:hash2) {
            if(!hash1.count(p) && v==1) ans.push_back(p);
        }
        return ans;
    }
    vector<string>get(string s){
        int pre=0,cur=0;
        vector<string>ans;
        for(;cur<s.size();cur++){
            while(cur<s.size()&&s[cur]!=' ')cur++;
            ans.push_back(s.substr(pre,cur-pre));
            pre=cur+1;
        }
        return ans;
    }
};