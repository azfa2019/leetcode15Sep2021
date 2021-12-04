class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>nextBig(n,INT_MAX);
        vector<int>prevBig(n,INT_MAX);
        stack<int>stack;
        for(int i=0;i<n;i++){
            if(stack.empty() || heights[stack.top()]>=heights[i]){
                stack.push(i);
            }else{
                while(!stack.empty() && heights[stack.top()]<heights[i]){
                    nextBig[stack.top()]=i;
                    stack.pop();
                }
                stack.push(i);
            }
        }
        while(!stack.empty()) stack.pop();
        for(int i=0;i<n;i++){
            if(stack.empty() || heights[stack.top()]>=heights[i]){
                if(!stack.empty()) prevBig[i]=stack.top();
                stack.push(i);
            }else{
                while(!stack.empty() && heights[stack.top()]<heights[i]) stack.pop();
                if(!stack.empty()) prevBig[i]=stack.top();
                stack.push(i);
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++) if(prevBig[i]!=INT_MAX) ans[prevBig[i]]++;
        for(int i=0;i<n;i++){
            int next=nextBig[i];
            if(next!=INT_MAX) ans[i]++;
        }
        return ans;
    }
};
//10 8 5 6
