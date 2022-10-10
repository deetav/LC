class Solution {
public:
    string breakPalindrome(string palindrome) {
            int N = (int) palindrome.size();
            if (N == 1) return "";
            if (N % 2) {
                    for (int i = 0; i < N; ++i) {
                            if (palindrome[i] != 'a') {
                                    if (i != (N / 2)) palindrome[i] = 'a';
                                    else palindrome.back() = 'b';
                                    return palindrome;
                            }
                    }
                    palindrome.back() = 'b';
                    return palindrome;
            } else {
                    for (int i = 0; i < N / 2; ++i) {
                            if (palindrome[i] != 'a') {
                                    palindrome[i] = 'a';
                                    return palindrome;
                            }
                    }
                    palindrome.back() = 'b';
                    return palindrome;
            }
            return "";
    }
};