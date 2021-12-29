class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>nextBig(n,-1);
        stack<int>stck;
        for(int i=0;i<n;i++){
            while(!stck.empty() && temperatures[i]>temperatures[stck.top()]) {
                nextBig[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nextBig[i]==-1) continue;
            ans[i]=nextBig[i]-i;
        }
        return ans;
    }
};
