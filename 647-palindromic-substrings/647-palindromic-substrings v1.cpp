class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=count(i,i,s,n);
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1]) ans+=count(i,i+1,s,n);
        return ans;
    }
    int count(int i,int j,string& s,int n){
        while(i>=0 && j<=n-1 && s[i]==s[j]) i--,j++;
        return (j-1-(i+1)+1+1)/2;
    }
    
};

// [x [x x x] x x x [x x x] x] x x x x x x x x x x x x x 
//  i    ij.  j  mC     i.   mR
//  x x x x
//    i j
// 
// 
