class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
            vector<int> cnt(10005, 0);
            vector<int> ans;
            for (auto e: nums) {
                    ++cnt[e];
                    if (cnt[e] == 2) {
                            ans.push_back(e);
                    }
            }
            for (int i = 0; i < (int) nums.size(); ++i) {
                    if (cnt[i + 1] == 0) ans.push_back(i + 1);
            }
            return ans;
    }
};