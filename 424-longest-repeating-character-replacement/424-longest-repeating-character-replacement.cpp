class Solution {
    public:
    int characterReplacement(string s, int k) {
        int left=0,ans=0,n=s.size();
        vector<int>count(26,0);
        for(int right=0;right<n;right++){
            count[s[right]-'A']++;
            while(right-left+1-*max_element(count.begin(),count.end())>k){
                count[s[left]-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};