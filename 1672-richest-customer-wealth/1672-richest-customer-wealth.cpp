class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
                int ans = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int temp = 0;//统计每一个客户的所有资产
            for (int j = 0; j < accounts[i].size(); j++) {
                temp += accounts[i][j];
            }
            //保留最大值
            ans = max(ans, temp);
        }
        return ans;

    }
};