class Solution {
public:
    int maxLength(vector<string> &arr) {
            vector<int> cnt(26, 0);
            int N = (int) arr.size();
            int ans = 0;
            for (int i = 0; i < (1 << N); ++i) {
                    bool F = true;
                    int temp = 0;
                    cnt.assign(26, 0);
                    for (int j = 0; j < N; ++j) {
                            F = true;
                            if (((1 << j) & i) != 0) {
                                    for (auto e: arr[j]) {
                                            ++cnt[e - 'a'];
                                            if (cnt[e - 'a'] > 1) {
                                                    F = false;
                                                    break;
                                            }
                                    }
                                    if (F) temp += (int) arr[j].size();
                            }
                    }
                    ans = max(ans, temp);
            }
            return ans;
    }
};