class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        int MOD = 10*9 + 7; 
        vector<int> subarray_sums;

        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                subarray_sums.push_back(current_sum);
            }
        }
        sort(subarray_sums.begin(), subarray_sums.end());

        long long result = 0;
        for (int k = left - 1; k < right; ++k) {
            result = (result + subarray_sums[k]) % MOD;
        }

    return static_cast<int>(result);
    }
};