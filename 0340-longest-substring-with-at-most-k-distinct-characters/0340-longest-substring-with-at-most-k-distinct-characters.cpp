class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l=0,n=s.size(),res=0;
        unordered_map<char,int>hash;
        for(int r=0;r<n;r++){
            hash[s[r]]++;
            while(hash.size()>k){
                char c=s[l];
                hash[s[l++]]--;
                if(hash[c]==0) hash.erase(c);
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};