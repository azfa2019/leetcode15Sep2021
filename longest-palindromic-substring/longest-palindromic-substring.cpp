class Solution {
    public:
    string longestPalindrome(string s) {
        string t="#";
        for(char c:s) t.push_back(c),t.push_back('#');
        int n=t.size();
        int maxR=-1,maxC=-1;
        vector<int>p(n);
        for(int i=0;i<n;i++){
            int r;
            if(maxR>=i){
                int j=2*maxC-i;
                r=min(maxR-i,p[j]);
                while(i-r>=0 && i+r<n && t[i-r]==t[i+r]) r++;
            }else{
                r=0;
                while(i-r>=0 && i+r<n && t[i-r]==t[i+r]) r++;
            }
            p[i]=r-1;
            if(i+p[i]>maxR){
                maxR=i+p[i];
                maxC=i;
            }
        }
        int maxLen=-1,center;
        for(int i=0;i<n;i++){
            if(p[i]>maxLen){
                maxLen=p[i];
                center=i;
            }
        }
        return s.substr(center/2-maxLen/2,maxLen);
    }
};
// x   {x   *   x   *   x   x   [*   x   *]   x}   x    
//              j       c            i        r
