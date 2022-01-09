class Solution {
public:
    bool isRobotBounded(string instructions) {
        int d=0;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        int x=0,y=0;
        for(auto ins:instructions){
            if(ins=='R') {
                d+=1;
            }else if (ins=='L'){
                d+=3;
            }else if(ins=='G'){
                d=d%4;
                x=x+dx[d];
                y=y+dy[d];
            }
        }
        return ((x==0 && y==0)||(d%4!=0));
    }
};