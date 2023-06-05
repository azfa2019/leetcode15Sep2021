class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        for(int i=2;i<c.size();i++){
            int x1=c[1][0]-c[0][0],y1=c[1][1]-c[0][1];
            int x2=c[i][0]-c[0][0],y2=c[i][1]-c[0][1];
            if(x1*y2-x2*y1) return false;
        }
        return true;
    }
};