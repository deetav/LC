class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
            map<string, int> M;
            for (auto e: words) ++M[e];
            vector<pair<int, string>> D;
            for (auto e: M) D.emplace_back(e.second, e.first);
            sort(D.begin(), D.end(), [&](const pair<int, string> &a, const pair<int, string> &b) {
                if (a.first == b.first) {
                        return a.second < b.second;
                }
                return a.first > b.first;
            });
            vector<string> ans;
            for (int i = 0; i < k; ++i) {
                    ans.push_back(D[i].second);
            }
            return ans;
    }
};