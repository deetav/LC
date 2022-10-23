//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

int steppingNumbers(int n, int m) {
        set<int> ans;
        function<void(int)> DFS = [&](int cur) {
            if (cur >= n && cur <= m) ans.insert(cur);
            if (cur > m) return;
            int R = cur % 10;
            int x = 10 * cur + R - 1;
            int y = 10 * cur + R + 1;
            if (R == 0) {
                    DFS(y);
            } else if (R == 9) DFS(x);
            else {
                    DFS(x);
                    DFS(y);
            }
        };
        for (int i = 0; i < 10; ++i) DFS(i);
        return (int) ans.size();
}
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends