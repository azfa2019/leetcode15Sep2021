class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        bool st[9];
        for(int i=0;i<9;i++){
            memset(st,0,sizeof st);
            for(int j=0;j<9;j++){
                if(b[i][j]!='.'){
                    int t=b[i][j]-'1';
                    if(st[t]) return false;
                    st[t]=true;
                }
            }
        }
        for(int i=0;i<9;i++){
            memset(st,0,sizeof st);
            for(int j=0;j<9;j++){
                if(b[j][i]!='.'){
                    int t=b[j][i]-'1';
                    if(st[t]) return false;
                    st[t]=true;
                }
            }
        }
        for(int i=0;i<9;i+=3)
            for(int j=0;j<9;j+=3){
                memset(st,0,sizeof st);
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        if(b[i+x][j+y]!='.'){
                            int t=b[i+x][j+y]-'1';
                            if(st[t]) return false;
                            st[t]=true;
                        }
                    }
                }
            }
        return true;
    }
};