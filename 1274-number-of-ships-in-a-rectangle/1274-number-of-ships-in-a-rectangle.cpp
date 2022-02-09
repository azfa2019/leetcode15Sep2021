/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int x0=bottomLeft[0],y0=bottomLeft[1];
        int x1=topRight[0],y1=topRight[1];
        int xm=(x0+x1)/2,ym=(y0+y1)/2;
        if(x0==x1 && y0==y1) return sea.hasShips(topRight,bottomLeft);
        int nbl=xm>=x0 && ym>=y0 && sea.hasShips({xm,ym},{x0,y0})? countShips(sea,{xm,ym},{x0,y0}) : 0;
        int ntr=xm+1<=x1 && ym+1<=y1 && sea.hasShips({x1,y1},{xm+1,ym+1})? countShips(sea,{x1,y1},{xm+1,ym+1}) : 0;
        int nbr=x1>=xm+1 && ym>=y0 && sea.hasShips({x1,ym},{xm+1,y0})? countShips(sea,{x1,ym},{xm+1,y0}) : 0;
        int ntl=xm>=x0 && y1>=ym+1 && sea.hasShips({xm,y1},{x0,ym+1})? countShips(sea,{xm,y1},{x0,ym+1}) : 0;
        return nbl+ntr+nbr+ntl;
    }
};