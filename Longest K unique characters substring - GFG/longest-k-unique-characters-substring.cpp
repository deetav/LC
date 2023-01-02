//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    int longestKSubstr(string s, int k) {
        vector<int> cnt(27,0);
        int unique_char = 0;
        for(auto e : s) {
            if(cnt[e - 'a'] == 0){
                ++unique_char;
            }
            ++cnt[e - 'a'];
        }
        if(unique_char < k){
            return -1;
        }
        cnt.assign(27,0);
        int L = 0, R = 0;
        int smax = 1;
        ++cnt[s[0] - 'a'];
        for(int i = 1; i < (int)s.size(); ++i){
            ++cnt[s[i] - 'a'];
            ++R;
            int temp = 0;
            for(int j = 0; j < 26; ++j){
                temp += (cnt[j] != 0);
            }
            if(temp > k){
                --cnt[s[L] - 'a'];
                ++L;
            }
            if(R - L + 1 > smax){
                smax = R - L + 1;
            }
        }
        return smax;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends