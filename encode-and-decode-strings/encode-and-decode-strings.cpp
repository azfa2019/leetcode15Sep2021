class Codec {
    public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(auto s:strs){
            auto len=to_string(s.size());
            ans+=len+"#"+s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>ans;
        while(s!=""){
            int pos=s.find("#");
            int len=stoi(s.substr(0,pos));
            ans.push_back(s.substr(pos+1,len));
            s=s.substr(pos+len+1);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
// # a b c d
// p 