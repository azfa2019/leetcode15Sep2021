class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>hash0(26);
        for(char c:chars) hash0[c-'a']++;
        int res=0;
        for(string& s:words){
            bool flag=true;
            auto hash=hash0;
            for(char& c:s){
                if(--hash[c-'a']<0) {
                    flag=false;
                    break;
                }
            }
            if(flag) res+=s.size();
        }
        return res;
    }
};