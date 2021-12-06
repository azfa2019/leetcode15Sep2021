class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextLess(n,-1);
        vector<int>prevBig(n,n);
        stack<int>stack;
        for(int i=0;i<n;i++){
            while(!stack.empty() && nums[stack.top()]>nums[i]) {
                nextLess[stack.top()]=i;
                stack.pop();
            }
            stack.push(i);
        }
        //for(int i=0;i<n;i++) cout<<i<<","<<nextLess[i]<<" ";
        //cout<<endl;
        
        while(!stack.empty()) stack.pop();
        for(int i=n-1;i>=0;i--){
            while(!stack.empty() && nums[i]>nums[stack.top()]){
                prevBig[stack.top()]=i;
                stack.pop();
            }
            stack.push(i);
        }
        //for(int i=0;i<n;i++) cout<<i<<","<<prevBig[i]<<" ";
        //cout<<endl;
        int ans=n;
        for(int i=0;i<n;i++){
            if(nextLess[i]>i || prevBig[i]<i) ans--;
        }
        return ans;
    }
};
// -1 1 3 5 2
//if nextLess[i]>i, no, 2
//if prevBig[i]<i, no, 1
