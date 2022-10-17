class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
            int N = (int) nums.size();
            int cur_odd = 0, ans = 0, L = 0, even = 0;
            for (int i = 0; i < N; ++i) {
                    cur_odd += (nums[i] % 2);
                    if (nums[i] % 2) {
                            even = 1;
                            if (cur_odd >= k) {
                                    while (nums[L++] % 2 == 0) ++even;
                                    ans += (even);
                            }
                    } else {
                            if (cur_odd >= k) ans += (even);
                    }
            }
            return ans;
    }
};