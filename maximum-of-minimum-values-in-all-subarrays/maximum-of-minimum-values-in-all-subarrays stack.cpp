class Solution {
    public:
    vector<int> findMaximums(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextLess(n,n);
        vector<int>prevLess(n,-1);
        stack<int>stack;
        for(int i=0;i<n;i++){
            while(!stack.empty() && nums[stack.top()]>nums[i]){
                nextLess[stack.top()]=i;
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty()) stack.pop();
        for(int i=n-1;i>=0;i--){
            while(!stack.empty() && nums[i]<nums[stack.top()]){
                prevLess[stack.top()]=i;
                stack.pop();
            }
            stack.push(i);
        }
        //for(int i=0;i<prevLess.size();i++) cout<<i<<":"<<(i<0?-1:prevLess[i])<<" ";
        //cout<<endl;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++) {
            pq.push({nums[i],i});
        }

        for(int k=1;k<=n;k++){
            while(true){
                if(pq.empty()) break;
                int p=pq.top().second;
                if(nextLess[p]-prevLess[p]-1>=k) break;
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
// 10 20 10 50 40 10
// nextLess: 20, 10, len=2 elements, if nextLess[i]<=i+len, nextLess[i] will be the smaller
// 10: nexLess -1, 
// if len=3, nextLess[i]=5, > 2+3-1

//for len=1: n
// get all min, find the max of the min
// 10 20 50 10
