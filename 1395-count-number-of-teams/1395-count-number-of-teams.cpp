class Solution {
public:
    int numTeams(vector<int>& ra) {
        int n=ra.size(),ans=0;
        for(int j=1;j<n-1;j++){
            int iless=0,imore=0,kless=0,kmore=0;
            for(int i=0;i<j;i++){
                if(ra[i]<ra[j]) iless++;
                else if(ra[i]>ra[j]) imore++;
            }
            for(int k=j+1;k<n;k++){
                if(ra[k]<ra[j]) kless++;
                else if(ra[k]>ra[j]) kmore++;
            }
            ans+=iless*kmore+imore*kless;
        }
        return ans;
    }
};