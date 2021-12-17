class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        int n=nums.size();
        stack<int>stck;
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MAX);
        vector<int>nextLess(n+2,-1);
        vector<int>prevGreater(n+2,-1);
        for(int i=0;i<n+2;i++){
            while(!stck.empty() && nums[stck.top()]>=nums[i]){
                nextLess[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        while(!stck.empty()) stck.pop();
        for(int i=n+1;i>=0;i--){
            while(!stck.empty() && nums[stck.top()]<=nums[i]){
                prevGreater[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(prevGreater[i]==-1 && nextLess[i]==-1) ans++;
        }
        return ans;
    }
};
// -1 1 3 5 2
//if nextLess[i]>i, no, 2
//if prevBig[i]<i, no, 1
// 1 -1 3 2 9 6
// nextGreater = i+1
//prevLess=i-1
