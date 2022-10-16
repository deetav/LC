class Solution {
public:
    int dp[305][11];
    
    int minDifficulty(vector<int> &jobDifficulty, int d) {
            memset(dp, -1, sizeof(dp));
            int N = (int) jobDifficulty.size();
            if (N < d) return -1;
            function<int(int, int)> DP = [&](int idx, int d) {
                if (d == 1) {
                        int amax = -1;
                        for (int i = idx; i < N; ++i) {
                                amax = max(amax, jobDifficulty[i]);
                        }
                        return amax;
                }
                int &res = dp[idx][d];
                if (res != -1) return res;
                int smax = INT32_MIN;
                res = INT32_MAX;
                for (int i = idx; i <= N - d; ++i) {
                        smax = max(smax, jobDifficulty[i]);
                        res = min(res, smax + DP(i + 1, d - 1));
                }
                return res;
            };
            return DP(0, d);
    }
};