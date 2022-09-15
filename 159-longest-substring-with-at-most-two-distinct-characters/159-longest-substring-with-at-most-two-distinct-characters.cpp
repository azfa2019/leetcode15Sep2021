class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int>hash;
        int res=1;
        for(int i=0,j=0;i<s.size();i++){
            hash[s[i]]++;
            while(j<s.size()&&hash.size()>2) {
                hash[s[j]]--;
                if(hash[s[j]]==0) hash.erase(s[j]);
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};