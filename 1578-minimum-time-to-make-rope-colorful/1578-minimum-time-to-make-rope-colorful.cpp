class Solution {
public:
    int minCost(string colors, vector<int>& cost) {
        int res=0;
        for(int i=0;i<colors.size();i++){
            int j=i;
            int sum=0,mx=0;
           while(j<colors.size()&&colors[j]==colors[i]){
                sum+=cost[j];
                mx=max(mx,cost[j]);
               j++;
            }
            //cout<<sum<<" "<<mx<<endl;
            res+=sum-mx;
            i=j-1;
        }
        return res;
    }
};