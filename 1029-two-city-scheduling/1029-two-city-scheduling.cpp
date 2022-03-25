class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0,a=0,b=0;
        vector<int>diff0,diff1;
        for(int i=0;i<costs.size();i++){
            auto cost=costs[i];
            if(cost[0]<cost[1]) sum+=cost[0],a++,diff0.push_back(cost[1]-cost[0]);
            else sum+=cost[1],b++,diff1.push_back(cost[0]-cost[1]);
        }
//        for(auto item:diff){
//            cout<<item[0]<<","<<item[1]<<endl;
//        }
        //cout<<sum<<endl;
        sort(diff0.begin(),diff0.end());
        sort(diff1.begin(),diff1.end());
        int i=0;
        while(a>b) sum+=diff0[i++],a--,b++;
        i=0;
        while(a<b) sum+=diff1[i++],a++,b--;
        //if(a==b) return sum;
        return sum;
    }
};