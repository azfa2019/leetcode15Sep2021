class Solution {
    public:
    int maxPower(string s) {
        int n=s.size();
        int i=0;
        int ans=0;

        while(i<n){
            int j=i;
            while(j<n && s[i]==s[j]) j++;
            ans=max(ans,j-i);
            i=j;
        }
        return ans;
    }
};
