class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int res=0;
        vector<bool>visited(10,false);
        vector<vector<int>>jumps(10,vector<int>(10,0));
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
        res+=helper(1,1,m,n,jumps,visited,0)*4;
        res+=helper(2,1,m,n,jumps,visited,0)*4;
        res+=helper(5,1,m,n,jumps,visited,0);
        return res;
    }
    int helper(int num,int len,int m,int n,vector<vector<int>>&jumps,vector<bool>visited,int res){
        if(len>=m) res++;
        len++;
        if(len>n) return res;
        visited[num]=true;
        for(int ne=1;ne<=9;ne++){
            int jum=jumps[num][ne];
            if(!visited[ne]&&(jum==0||visited[jum]))
                res=helper(ne,len,m,n,jumps,visited,res);
        }
        visited[num]=false;
        return res;
    }
};