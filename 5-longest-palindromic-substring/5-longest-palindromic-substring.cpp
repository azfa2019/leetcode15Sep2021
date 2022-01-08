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
        for(int i=0;i<n;i++){
            int r;
            if(maxR>=i){
                int j=maxC*2-i;
                r=min(maxR-i,p[j]);
                while(i+r<n && i-r>=0 && t[i+r]==t[i-r]) r++;
            }else{
                r=0;
                while(i+r<n && i-r>=0 && t[i+r]==t[i-r]) r++;
            }
            p[i]=r-1;
            if(i+p[i]>maxR){
                maxR=i+p[i];
                maxC=i;
            }
        }
        int maxLen=0,center;
        for(int i=0;i<n;i++){
            if(maxLen<p[i]){
                maxLen=p[i];
                center=i;
            }
        }
        return s.substr(center/2-maxLen/2,maxLen);
    }
};
// x [x x x x x] x x x [x x x x x] x x x x 
//        j        mC       i        mR
//
//
//
//