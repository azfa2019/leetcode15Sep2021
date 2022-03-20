class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const int INF=0x3f3f3f3f;
        int res=INF;
        int n=tops.size();
        int val[]={tops[0],bottoms[0]};
        for(int x:val){
            int t=0;
            for(int i=0;i<n;i++){
                if(tops[i]!=x){
                    if(bottoms[i]!=x) t=INF;
                    else t++;
                }
            }
            res=min(res,t);
            t=0;
            for(int i=0;i<n;i++){
                if(bottoms[i]!=x){
                    if(tops[i]!=x) t=INF;
                    else t++;
                }
            }
            res=min(res,t);
        }
        return res==INF?-1:res;
    }
};