class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>map(26,0);
        int n=s.size();
        int left=0;
        int maxRepeat=0;
        int ans=0;
        for(int right=0;right<n;right++){
            char r=s[right];
            map[r-'A']++;
            maxRepeat=max(maxRepeat,map[r-'A']);
            while(right-left+1>maxRepeat+k){
                char l=s[left];
                map[l-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
