class Codec {
    public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans="";
        for(string s:strs){
            ans+=to_string(s.size())+"#"+s;
        }
        return ans;
    }
    //"Hello","World"
    //5#Hello5#World

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>ans;
        helper(s,ans);
        return ans;
    }
    void helper(string& s,vector<string>& ans){
        while(s!=""){
            int i=s.find("#",0);
            int len=stoi(s.substr(0,i));
            string cur=s.substr(i+1,len);
            ans.push_back(cur);
            s=s.substr(i+1+len);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));