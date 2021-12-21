class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>stck;
        int n=heights.size();
        vector<int>prevBig(n,-1);
        vector<int>nextBig(n,-1);
        for(int i=0;i<n;i++){
            while(!stck.empty() && heights[stck.top()]<=heights[i]){
                nextBig[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        while(!stck.empty()) stck.pop();
        for(int i=n-1;i>=0;i--){
            while(!stck.empty() && heights[stck.top()]<=heights[i]){
                prevBig[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
            if(prevBig[i]!=-1) ans[prevBig[i]]++;
        for(int i=0;i<n;i++)
            if(nextBig[i]>i) ans[i]++;
        return ans;
    }
};