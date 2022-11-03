class Solution {
public:
    int longestPalindrome(vector<string> &words) {
            map<string, int> M;
            int cnt = 0;
            for (auto e: words) ++M[e];
            bool F = false;
            for (auto e: words) {
                    if (e[0] == e[1]) {
                            if (M[e] >= 2) {
                                    M[e] -= 2;
                                    cnt += 4;
                            } else {
                                    if(M[e] > 0){
                                        F = true;
                                    --M[e];
                                    }
                            }
                    } else {
                            string y = e;
                            reverse(y.begin(), y.end());
                            if (M[y] > 0 && M[e] > 0) {
                                    --M[y];
                                    --M[e];
                                    cnt += 4;
                            }
                    }
            }
            if (F) cnt += 2;
            return cnt;
    }
};