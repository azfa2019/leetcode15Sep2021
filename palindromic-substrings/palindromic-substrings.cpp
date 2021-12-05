class Solution {
    public:
    int countSubstrings(string s) {
        string t="#";
        for(char c:s){
            t.push_back(c);
            t.push_back('#');
        }
        int maxR=-1,maxC=-1;
        int n=t.size();
        vector<int>p(n,0);
        for(int i=0;i<n;i++){
            int r;
            if(maxR>=i){
                int j=2*maxC-i;
                r=min(maxR-i,p[j]);
                while(i+r<n&& i-r>=0 && t[i+r]==t[i-r]) r++;
            }else{
                r=0;
                while(i+r<n&& i-r>=0 && t[i+r]==t[i-r]) r++;
            }
            p[i]=r-1;
            if(i+p[i]>maxR){
                maxR=i+p[i];
                maxC=i;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(p[i]+1)/2;
        }
        return ans;
    }
};

// {x  [x   x   x]   x   x   x   [x   x   x]   x}   x    x   x   x
//          j           ctr           i       maxR        
//p[i]=min(p[j],maxR-i)

//.        j     ctr     i     maxR
//.    *-*---*-*     * *.  * *
//x {x x x x x x  x  x x x x x x}   x x x 


//.                        maxR
//x {x x x x x  x  x x x x x}   x x 
//.  * *   * *     * *   * *
//.  ---------
//       j     ctr     i  