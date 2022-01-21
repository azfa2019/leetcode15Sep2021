class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,cur=0,total=0;
        int n=cost.size();
        for(int i=0;i<n;i++){
            cur+=gas[i]-cost[i];
            if(cur<0){
                cur=0;
                start=i+1;
            }
            total+=gas[i]-cost[i];
        }
        return total>=0?start:-1;
    }
};