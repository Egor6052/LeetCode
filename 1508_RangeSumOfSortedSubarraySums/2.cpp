class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       const int MOD = 1e9 + 7;
        vector<int> prefix_sums(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefix_sums[i + 1] = prefix_sums[i] + nums[i];
        }

        auto comp = [&prefix_sums](pair<int, int>& a, pair<int, int>& b) {
            return prefix_sums[a.second] - prefix_sums[a.first] > prefix_sums[b.second] - prefix_sums[b.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);

        for (int i = 0; i < n; ++i) {
            min_heap.push({i, i + 1});
        }

        long long result = 0;
        for (int k = 1; k <= right; ++k) {
            auto current = min_heap.top();
            min_heap.pop();
            int i = current.first, j = current.second;
            int current_sum = prefix_sums[j] - prefix_sums[i];

            if (k >= left) {
                result = (result + current_sum) % MOD;
            }

            if (j + 1 <= n) {
                min_heap.push({i, j + 1});
            }
        }

        return static_cast<int>(result);
    }
};