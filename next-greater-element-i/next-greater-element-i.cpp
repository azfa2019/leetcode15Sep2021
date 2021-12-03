class Solution {
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>stack;
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            if(stack.empty() || nums2[i]<=stack.top()){
                stack.push(nums2[i]);
            }else{
                while(!stack.empty() && stack.top()<nums2[i]){
                    map[stack.top()]=nums2[i];
                    stack.pop();
                }
                stack.push(nums2[i]);
            }
        }
        while(!stack.empty()) {
            map[stack.top()]=-1;
            stack.pop();
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
            ans.push_back(map[nums1[i]]);
        return ans;
    }
};
// 1 2 3 4 2
// 4 2 1 3