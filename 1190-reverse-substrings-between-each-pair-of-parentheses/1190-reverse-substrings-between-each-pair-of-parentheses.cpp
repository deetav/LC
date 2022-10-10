class Solution {
public:
    string reverseParentheses(string s) {
            stack<int> idx;
            int N = (int) s.size();
            for (int i = 0; i < N; ++i) {
                    if (s[i] == '(') idx.push(i);
                    else if (s[i] == ')') {
                            int T = idx.top();
                            idx.pop();
                            reverse(s.begin() + T + 1, s.begin() + i);
                    }
            }
            string ans;
            for (auto e: s) {
                    if (e != '(' && e != ')') ans += e;
            }
            return ans;
    }
};
