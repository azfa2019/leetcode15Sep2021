class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i)
            if (manager[i] >= 0)
                g[manager[i]].push_back(i); // 建树
        function<int(int)> dfs = [&](int x) -> int {
            int maxPathSum = 0;
            for (int y: g[x]) // 遍历 x 的儿子 y（如果没有儿子就不会进入循环）
                maxPathSum = max(maxPathSum, dfs(y));
            return maxPathSum + informTime[x];
        };
        return dfs(headID); // 从根节点 headID 开始递归
    }
};