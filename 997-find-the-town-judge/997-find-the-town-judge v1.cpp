class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>dout(n+1),din(n+1);
        for(auto e:trust){
            din[e[1]]++;
            dout[e[0]]++;
        }
        int res=-1;
        for(int i=1;i<=n;i++){
            if(dout[i]==0 && din[i]==n-1){
                if(res!=-1) return -1;
                res=i;
            }
        }
        return res;
    }
};
