class Solution {
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
            int start = 0, minstart = -1, maxstart = -1, N = (int) nums.size();
            long long res = 0;
            bool minfound = false, maxfound = false;
            for (int i = 0; i < N; ++i) {
                    if (nums[i] < minK || nums[i] > maxK) {
                            start = i + 1;
                            minfound = false;
                            maxfound = false;
                            continue;
                    }
                    if (nums[i] == minK) {
                            minstart = i;
                            minfound = true;
                    }
                    if (nums[i] == maxK) {
                            maxstart = i;
                            maxfound = true;
                    }
                    if (minfound && maxfound) {
                            res += min(maxstart, minstart) - start + 1;
                    }
            }
            return res;
    }
};