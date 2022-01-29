class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>>mp;
        for(auto s:strings){
            string key=helper(s);
            mp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto item:mp){
            ans.push_back(item.second);
        }
        return ans;
    }
    string helper(string s){
        char c0=s[0];
        int diff=s[0]-'a';
        string ans="a";
        for(int i=1;i<s.size();i++){
            char c=s[i]-diff;
            if(c<'a') c+=26;
            ans.push_back(c);
        }
        return ans;
    }
};
