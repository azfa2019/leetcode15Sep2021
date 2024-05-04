class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        sort(p.begin(),p.end());
        int res=0;
        for(int i=0,j=p.size()-1;i<=j;j--){
            if(p[i]+p[j]<=l) i++;
            res++;
            
        }
        return res;
    }
};