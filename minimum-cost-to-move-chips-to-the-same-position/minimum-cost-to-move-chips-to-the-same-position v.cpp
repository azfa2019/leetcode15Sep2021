class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
        int ans=INT_MAX;
        for(int i=1;i<=100;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if((position[j]-i)%2==0) continue;
                sum+=abs((position[j]-i)%2);
            }
            ans=min(sum,ans);
        }
        return ans;
    }
};
// 2 2 2 3 3 5
