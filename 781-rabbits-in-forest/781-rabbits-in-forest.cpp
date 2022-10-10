class Solution {
public:
    int numRabbits(vector<int> &answers) {
            vector<int> cnt(1005, 0);
            int ans;
            for (auto e: answers) {
                    if (e == 0) ++ans;
                    else {
                            if (!cnt[e]) ans += (e + 1);
                            ++cnt[e];
                            if (cnt[e] == (e + 1)) {
                                    cnt[e] = 0;
                            }
                    }
            }
            return ans;
    }
};