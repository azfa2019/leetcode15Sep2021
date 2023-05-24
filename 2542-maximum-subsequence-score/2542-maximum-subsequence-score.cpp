typedef pair<int,int> PII;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int K) {
        int n = nums1.size();

        // 下标按 nums2[i] 从大到小排序
        typedef pair<int, int> pii;
        vector<pii> ord;
        for (int i = 0; i < n; i++) ord.push_back(pii(-nums2[i], i));
        sort(ord.begin(), ord.end());

        // 先把排序后 nums1 前 K 个元素加入小根堆，并计算它们的和
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sm = 0;
        for (int i = 0; i < K; i++) {
            int j = ord[i].second;
            pq.push(nums1[j]);
            sm += nums1[j];
        }
        // 计算初始答案
        long long ans = nums2[ord[K - 1].second] * sm;

        // 枚举 nums2 中的最小值
        for (int i = K; i < n; i++) {
            int j = ord[i].second;
            // 小根堆新加入一个 nums1 中的数
            pq.push(nums1[j]);
            sm += nums1[j];
            // 要去掉最小的数，使得小根堆的大小等于 K
            int x = pq.top(); pq.pop();
            sm -= x;
            // 计算当前答案
            ans = max(ans, nums2[j] * sm);
        }
        return ans;
    }
};