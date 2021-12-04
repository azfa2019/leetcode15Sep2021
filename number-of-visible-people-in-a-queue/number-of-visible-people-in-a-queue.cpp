class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n,0);
        stack<int>stack;
        for(int i=n-1;i>=0;i--){
            int count=0;
            if(stack.empty() || heights[stack.top()]>=heights[i]){
                if(!stack.empty()) ans[i]=1;
                stack.push(i);
            }else{
                while(!stack.empty() && heights[i]>heights[stack.top()]){
                    count++;
                    stack.pop();
                }
                if(!stack.empty()) count++;
                stack.push(i);
                ans[i]=count;
            }
        }
        return ans;
    }
};
// 0. 1 2 3 4  5
// 10 6 8 5 11 9
// 11, count=1, ans[4]=1
// 5 11, count=0, ans[]=
// 8 11, count=1, ans[2]=