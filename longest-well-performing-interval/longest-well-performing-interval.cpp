class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        vector<int>presum{0};
        int sum=0;
        for(int h:hours){
            if(h>8) sum+=1;
            else sum+=-1;
            presum.push_back(sum);
        }
        
        stack<int>stck;
        for(int i=0;i<presum.size();i++){
            if(stck.empty() || presum[stck.top()]>presum[i])
                stck.push(i);
        }
        int ans=0;
        for(int j=presum.size()-1;j>=0;j--){
            while(!stck.empty() && presum[j]>presum[stck.top()]) {
                ans=max(ans,j-stck.top());
                stck.pop();
            }
        }
        return ans;
    }
};