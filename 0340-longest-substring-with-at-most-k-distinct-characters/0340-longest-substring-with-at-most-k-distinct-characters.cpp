class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int>hash;
        int res=0;
        int n=s.size();
        for(int r=0,l=0;r<n;r++){
            hash[s[r]]++;
            while(hash.size()>k){
                hash[s[l]]--;
                if(!hash[s[l]]) hash.erase(s[l]);
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};