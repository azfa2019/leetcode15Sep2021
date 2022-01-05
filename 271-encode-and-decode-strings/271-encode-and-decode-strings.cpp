class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans="";
        for(string s:strs)
            ans+=to_string(s.size())+"#"+s;
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>ans;
        dfs(s,ans);
        return ans;
    }
    void dfs(string& s,vector<string>&ans){
        if(s.size()==0) return;
        int i=s.find("#",0);
        int len =stoi(s.substr(0,i));
        string cur=s.substr(i+1,len);
        ans.push_back(cur);
        string next=s.substr(i+1+len);
        dfs(next,ans);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));