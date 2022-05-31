class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.size()) return 0;

        int cur = 0;
        for(int i = 0; i < k - 1; i ++)
            cur = 2 * cur + (s[i] == '1');

        unordered_set<int> set;
        for(int i = k - 1; i < s.size(); i ++){
            cur = cur * 2 + (s[i] == '1');
            set.insert(cur);
            cur &= ~(1 << (k - 1));
        }
        return set.size() == (1 << k);

    }
};