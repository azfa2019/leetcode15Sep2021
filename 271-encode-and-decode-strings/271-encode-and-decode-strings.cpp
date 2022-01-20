class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(string s:strs){
            ans+=to_string(s.size())+"!"+s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>ans;
        while(s!=""){
            int pos=s.find("!");
            int len=stoi(s.substr(0,pos));
            string cur=s.substr(pos+1,len);
            ans.push_back(cur);
            s=s.substr(pos+1+len);
        }
        return ans;
    }
};
//  w  orld
// p1     5

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));