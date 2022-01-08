class Solution {
    string s;
    int n;
    public:
    string longestPalindrome(string s) {
        this->s=s;
        this->n=s.size();
        int maxLen=0,start=0,len;
        for(int i=0;i<n;i++){
            len=expand(i,i);
            if(maxLen<len){
                maxLen=len;
                start=i-len/2;
            }
            // 1 2 3 4 5
        }
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1]){
                len=expand(i,i+1);
                if(maxLen<len){
                    maxLen=len;
                    start=i-len/2+1;
                }
                // 1 2 3 4 
            }
        return s.substr(start,maxLen);
    }
    int expand(int i,int j){
        while(i>=0 && j<n && s[i]==s[j]) 
            i--,j++;
        return j-1-(i+1)+1;
    }
};