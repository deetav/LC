class Solution {
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
            int N = (int) plantTime.size();
            vector<pair<int, int>> M(N);
            for (int i = 0; i < N; ++i) M[i] = {growTime[i], plantTime[i]};
            sort(M.begin(), M.end(), __greater());
            int ans = 0;
            int smin = 0;
            for (int i = 0; i < N; ++i) {
                    smin += M[i].second;
                    ans = max(ans, M[i].first + smin);
            }
            return ans;
    }
};