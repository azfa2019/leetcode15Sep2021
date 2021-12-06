class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int n=s.size();
        unordered_map<char,int>map;
        int maxLen=0;
        for(int right=0;right<n;right++){
            char r=s[right];
            map[r]++;
            while(left<right && map[r]>1){
                char l=s[left++];
                map[l]--;
            }
            int len=right-left+1;
            maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};