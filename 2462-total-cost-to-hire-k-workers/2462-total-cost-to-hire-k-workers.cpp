class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<int,vector<int>,greater<>>pq0,pq1;
        int i=0,j=costs.size()-1;
        long long ans=0;
        while(k--){
            while(pq0.size()<c && i<=j) pq0.push(costs[i++]);
            while(pq1.size()<c && i<=j) pq1.push(costs[j--]);
            int a=(pq0.size()?pq0.top():INT_MAX);
            int b=(pq1.size()?pq1.top():INT_MAX);
            if(a<=b) {
                ans+=a;
                pq0.pop();
            }else{
                ans+=b;
                pq1.pop();
            }
        }
        return ans;
    }
};