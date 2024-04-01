class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int>hash;
        int l=0,n=s.size(),res=0;
        for(int r=0;r<n;r++){
            hash[s[r]]++;
            while(hash.size()>2){
                char c=s[l];
                hash[s[l++]]--;
                if(!hash[c]) hash.erase(c);
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};