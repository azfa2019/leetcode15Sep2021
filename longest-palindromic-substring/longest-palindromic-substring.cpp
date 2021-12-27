class Solution {
    int n;
    string s;
    public:
    string longestPalindrome(string s) {
        int maxLen=0;
        this-> n=s.size();
        this-> s=s;
        string ans;
        for(int i=0;i<n;i++){
            int curLen=expand(i,i);
            if(curLen>maxLen) {
                maxLen=curLen;
                ans=s.substr(i-curLen/2,curLen);
            }
            if(i==1) cout<<curLen<<" "<<ans;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                int curLen=expand(i,i+1);
                if(curLen>maxLen) {
                    maxLen=curLen;
                    ans=s.substr(i-curLen/2+1,curLen);
                }
            }
        }
        return ans;
    }
    int expand(int i,int j){
        while(i>=0 && j<n && s[i]==s[j]) i--,j++;
        return j-1-(i+1)+1; 
    }
};
// bab
// 012
// baab
// 0123
// cbaabc
// 012345