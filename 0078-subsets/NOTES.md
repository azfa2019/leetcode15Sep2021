1. 循环遍历
```
class Solution {
public:
vector<vector<int>>res;
vector<int>path;
int n;
vector<int>nums;
vector<vector<int>> subsets(vector<int>& _nums) {
nums=_nums;
n=nums.size();
dfs(0);
return res;
}
void dfs(int start){
res.push_back(path);
for(int i=start;i<n;i++){
path.push_back(nums[i]);
dfs(i+1);
path.pop_back();
}
}
};
```
2. 选与不选