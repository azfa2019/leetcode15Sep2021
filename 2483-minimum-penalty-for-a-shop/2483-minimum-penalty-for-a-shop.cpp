class Solution {
public:
    int bestClosingTime(string customers) {
        int ans=0,cost=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='N') cost++;
            else{
                cost--;
                if(cost<0) {
                    ans=i+1;
                    cost=0;
                }
            }
        }
        return ans;
    }
};