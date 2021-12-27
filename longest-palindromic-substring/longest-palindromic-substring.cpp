class Solution {
public:
    string longestPalindrome(string s) {
        string t="#";
        for(char c:s){
            t.push_back(c);
            t.push_back('#');
        }
        int n=t.size();
        int maxC=-1,maxR=-1;
        vector<int>p(n,0);
        int maxLen=0,center=0;
        for(int i=0;i<n;i++){
            int r;
            if(maxR>=i){
                int j=2*maxC-i;
                r=min(p[j],maxR-i);
                while(i-r>=0 && i+r<n && t[i-r]==t[i+r]) r++;
            }else{
                r=0;
                while(i-r>=0 && i+r<n && t[i-r]==t[i+r]) r++;
            }
            p[i]=r-1;
            if(maxR<i+p[i]){
                maxR=i+p[i];
                maxC=i;
            }
            if(maxLen<p[i]) {
                maxLen=p[i];
                center=i;
            }
        }
        return s.substr(center/2-maxLen/2,maxLen);
    }
};
// [x [x x x] x x x [x x x] x] x x x x x x x x x x x x x x x x x 
//       j      mC     i    mR