class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        int n=co.size();
        double eps=1e-8;
        double x0=co[0][0],y0=co[0][1];
        double x1=co[1][0],y1=co[1][1];
        if(x1-x0==0){
            for(int i=2;i<n;i++)
                if(co[i][0]-x0!=0) return false;
            return true;
        }
        else{
            double k=(y1-y0)/(x1-x0);
            //cout<<k<<endl;
            for(int i=2;i<n;i++)
                if (fabs((co[i][1]-y0)/(co[i][0]-x0)-k)>eps) return false;
            return true;
    }
    
        
    }
};