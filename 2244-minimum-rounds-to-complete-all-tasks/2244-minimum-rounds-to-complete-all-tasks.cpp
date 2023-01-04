class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> cnt;
        for (int x : tasks) cnt[x]++;
        int ans = 0;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            int x = it->second;
            if (x == 1) return -1;
            else if (x == 2) ans++;
            else if (x % 3 == 0) ans += x / 3;
            else ans += x / 3 + 1;
        }
        return ans;
    }
};
