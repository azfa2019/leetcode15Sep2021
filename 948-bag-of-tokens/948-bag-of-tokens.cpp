class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        sort(t.begin(),t.end());
        int l=0,r=t.size()-1;
        int s=0,res=0;
        while(l<=r){
            while(l<=r&&p>=t[l]) s++,p-=t[l],l++;
            res=max(res,s);
            if(l<=r&&res>0) s--,p+=t[r],r--;
            else break;
        }
        return res;
    }
};
// res p   l   r
// 0   200 0   3
// 1   100 1   3
// 0    500 1   2
//