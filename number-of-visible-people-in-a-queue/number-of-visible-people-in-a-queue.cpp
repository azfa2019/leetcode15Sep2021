class Solution {
    public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int>stck;
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            int count=0;
            if(stck.empty() || heights[i]<heights[stck.top()]){
                if(!stck.empty())  ans[i]=1;
                stck.push(i);
            }else{
                while(!stck.empty() && heights[i]>heights[stck.top()]){
                    count++;
                    stck.pop();
                }
                if(!stck.empty()) count++;
                ans[i]=count;
                stck.push(i);
            }
        }
        return ans;
    }
};