int dp[101][28][101][101];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
            int N = (int) s.size();
            memset(dp, -1, sizeof(dp));
            function<int(int, int, int, int)> DP = [&](int idx, int last, int length, int remain) {
                if (remain < 0) return INT32_MAX;
                if (idx >= N) return 0;
                int &res = dp[idx][last][length][remain];
                if (res != -1) return res;
                int D = DP(idx + 1, last, length, remain - 1);
                int keep = 0;
                if ((s[idx] - 'a') == last) {
                        if (length == 1 || length == 9 || length == 99) ++keep;
                        keep += DP(idx + 1, last, length + 1, remain);
                } else keep = 1 + DP(idx + 1, s[idx] - 'a', 1, remain);
                res = min(keep, D);
                return res;
            };
            return DP(0, 27, 0, k);
    }
};