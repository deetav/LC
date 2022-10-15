class Solution {
public:
    int minimizeArrayValue(vector<int> &nums) {
            auto ok = [&](int x) {
                int N = (int) nums.size();
                if (x < nums[0]) return false;
                long long prev = nums[0];
                for (int i = 1; i < N; ++i) {
                        long long D = x - prev;
                        prev = nums[i] - D;
                        if (prev > x) return false;
                }
                
                return true;
            };
            int L = -1, R = (int) 1e9 + 7;
            while (L + 1 < R) {
                    int M = L + (R - L) / 2;
                    if (ok(M)) R = M;
                    else L = M;
            }
            return R;
    }
};