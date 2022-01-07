class Solution {
public:
    int countSubstrings(string s) {
        string tmp=s;
        s="#";
        for(char c:tmp){
            s.push_back(c);
            s.push_back('#');
        }
        int maxC=0,maxR=0;
        int n=s.size();
        vector<int>p(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            int r;
            if(maxR>=i){
                int j=2*maxC-i;
                r=min(p[j],maxR-i);
                while(i-r>=0 && i+r<n && s[i-r]==s[i+r]) r++;
            }else{
                r=0;
                while(i-r>=0 && i+r<n && s[i-r]==s[i+r]) r++;
            }
            p[i]=r-1;
            if(maxR<i+p[i]){
                maxR=p[i];
                maxC=i;
            }
        }
        for(auto e:p)
            count+=(e+1)/2;
        return count;
    }
};
// [x x x x x x x x x x x x x] x x x x x 
//      j       mC      i   mR 
// 
// 
// 
// 