/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<bool>st(n,true);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(i!=j && st[i]){
                    if(knows(i,j) || !knows(j,i)) {
                        st[i]=false;
                        break;
                    }else st[j]=false;
                }
            }
        int res=-1;
        for(int i=0;i<n;i++) if(st[i]) res=i;
        return res;
    }
};