class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,cur=0,start=0;
        for(int i=0;i<cost.size();i++){
            cur+=gas[i]-cost[i];
            if(cur<0){
                start=i+1;
                cur=0;
            }
            total+=gas[i]-cost[i];
        }
        return total>=0?start:-1;
    }
};