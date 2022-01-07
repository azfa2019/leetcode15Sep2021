class Solution {
    int n;
    string s;
public:
    int countSubstrings(string s) {
        this->n=s.size();
        this->s=s;
        int ans=0;
        for(int i=0;i<n;i++) ans+=expand(i,i);
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) ans+=expand(i,i+1);
        }
        return ans;
    }
    int expand(int i,int j){
        int count=0;
        while(i>=0 && j<=n-1 && s[i]==s[j]){
            count++;
            i--,j++;
        }
        return count;
    }
};
// b a a b