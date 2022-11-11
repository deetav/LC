//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
int characterReplacement(string s, int k) {
        int ans = 0;
        int N = (int) s.size();
        for (char i = 'A'; i <= 'Z'; ++i) {
                int cnt = 0;
                int R = 0;
                for (int j = 0; j < N; ++j) {
                        if (j) {
                                if (s[j - 1] != i) --cnt;
                        }
                        while (R < N && cnt <= k) {
                                if (s[R] == i) ++R;
                                else {
                                        if(cnt==k) break;
                                        ++cnt;
                                        ++R;
                                }
                        }
                        ans = max(ans, R - j);
                }
        }
        return ans;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends