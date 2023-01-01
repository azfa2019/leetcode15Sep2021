class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(j<s.size() && s[j]!=' ') j++;
            words.push_back(s.substr(i,j-i));
            i=j+1;
        }
        //for(auto& w:words) cout<<w<<endl;
        if(words.size()!=pattern.size()) return false;
        unordered_map<char,string>hash1;
        unordered_map<string,char>hash2;
        for(int i=0;i<pattern.size();i++){
            if(hash1.count(pattern[i]) && hash2.count(words[i])){
                if(hash1[pattern[i]]!=words[i]||hash2[words[i]]!=pattern[i]) return false;
            }else if(!hash1.count(pattern[i])&& !hash2.count(words[i])){
                hash1[pattern[i]]=words[i];
                hash2[words[i]]=pattern[i];
            }else return false;
        }
        return true;
    }
};