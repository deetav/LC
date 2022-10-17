class Solution {
public:
    bool checkIfPangram(string sentence) {
            vector<int> cnt(26, 0);
            for (auto e: sentence) ++cnt[e - 'a'];
            for (int i = 0; i < 26; ++i) {
                    if(!cnt[i]) return false;
            }
            return true;
    }
};
