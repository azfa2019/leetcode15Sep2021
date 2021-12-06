class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            int len=expand(i,i,s);
            count+=(len+1)/2;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) {
                int len=expand(i,i+1,s);
                count+=(len+1)/2;
            }
        }
        return count;
    }
    int expand(int l,int r,string& s){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return (r-1)-(l+1)+1;
    }
};
// d a a d